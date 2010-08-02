#include "database/TypeCodeDB.h"
#include "eProsima_cpp/eProsimaLog.h"

#include "cdr/cdr_stream.h"
#include "cdr/cdr_typeCode.h"
#include "osapi/osapi_heap.h"

#define TYPECODE_TABLE "typecodes"
#define BUFFER_LENGTH 2048

using namespace eProsima;
using namespace std;

static const char* const CLASS_NAME = "TypeCodeDB";
static const char* const TYPECODE_ADD = "INSERT INTO " TYPECODE_TABLE " VALUES(?, ?, ?)";

eTypeCode::eTypeCode(const char *topicName, const char *typeName,
        struct RTICdrTypeCode *typeCode) : m_topicName(topicName),
    m_typeName(typeName), m_typeCode(typeCode)
{
}

eTypeCode::~eTypeCode()
{
    RTIOsapiHeap_freeBufferNotAligned(m_typeCode);
}

bool eTypeCode::equal(const char *topicName, const char *typeName)
{
    const char* const METHOD_NAME = "equal";
    bool returnedValue = false;

    if(topicName != NULL && typeName != NULL)
    {
        if(strcmp(m_topicName.c_str(), topicName) == 0 &&
                strcmp(m_typeName.c_str(), typeName) == 0)
            returnedValue = true;
    }
    else
    {
        printError("Bad parameters");
    }

    return returnedValue;
}

TypeCodeDB::TypeCodeDB(eProsimaLog &log, sqlite3 *databaseH) : m_log(log), m_ready(false),
    m_databaseH(databaseH), m_addStmt(NULL)
{
    const char* const METHOD_NAME = "TypeCodeDB";
    const char* const TABLE_CHECK = "SELECT name FROM sqlite_master WHERE name='" TYPECODE_TABLE "'";
    const char* const TABLE_TRUNCATE = "DELETE FROM " TYPECODE_TABLE;
    const char* const TABLE_CREATE = "CREATE TABLE " TYPECODE_TABLE " (topic_name VARCHAR(50)," \
                                      "type_name VARCHAR(50), typecode VARCHAR(2048)," \
                                      "PRIMARY KEY(topic_name, type_name))";
    sqlite3_stmt *stmt = NULL;
    int ret = SQLITE_ERROR;

    if(sqlite3_prepare_v2(m_databaseH, TABLE_CHECK, strlen(TABLE_CHECK), &stmt, NULL) == SQLITE_OK)
    {
        ret = sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if(ret == SQLITE_ROW)
        {
            if(sqlite3_prepare_v2(m_databaseH, TABLE_TRUNCATE, strlen(TABLE_TRUNCATE), &stmt, NULL) == SQLITE_OK)
            {
                if(sqlite3_step(stmt) == SQLITE_DONE)
                    m_ready = true;
                else
                    logError(m_log, "Cannot truncate the typecodes table");

                sqlite3_finalize(stmt);
            }
        }
        else if(ret == SQLITE_DONE)
        {
            if(sqlite3_prepare_v2(m_databaseH, TABLE_CREATE, strlen(TABLE_CREATE), &stmt, NULL) == SQLITE_OK)
            {
                if(sqlite3_step(stmt) == SQLITE_DONE)
                    m_ready = true;
                else
                    logError(m_log, "Cannot create the typecodes table");

                sqlite3_finalize(stmt);
            }
        }
        else
        {
            logError(m_log, "Cannot execute check the typecodes table");
        }

        if(m_ready)
        {
            m_ready = false;

            if(sqlite3_prepare_v2(m_databaseH, TYPECODE_ADD, strlen(TYPECODE_ADD), &m_addStmt, NULL) == SQLITE_OK)
            {
                m_buffer = (char*)calloc(BUFFER_LENGTH, sizeof(char));

                if(m_buffer != NULL)
                    m_ready = true;
            }
            else
                logError(m_log, "Cannot create add statement");
                
        }
    }
    else
    {
        logError(m_log, "Cannot check the typecodes table");
    }
}

TypeCodeDB::~TypeCodeDB()
{
    list<eTypeCode*>::iterator it;

    for(it = m_typecodes.begin(); it != m_typecodes.end(); it++)
    {
        delete *it;
    }
}

bool TypeCodeDB::addTypecode(const char *topicName, const char *typeName,
                    struct RTICdrTypeCode *typeCode)
{
    const char* const METHOD_NAME = "addTypeCode";
    bool returnedValue = false;
    char *buffer = NULL;

    if(m_ready)
    {
        if(!findTypecode(topicName, typeName))
        {
            if(sqlite3_reset(m_addStmt) == SQLITE_OK)
            {
                sqlite3_bind_text(m_addStmt, 1, topicName, strlen(topicName), SQLITE_STATIC);
                sqlite3_bind_text(m_addStmt, 2, typeName, strlen(typeName), SQLITE_STATIC);
                buffer = getPrintIDL(typeCode);
                if(buffer != NULL)
                    sqlite3_bind_text(m_addStmt, 3, buffer, strlen(buffer), SQLITE_STATIC);

                if(sqlite3_step(m_addStmt) == SQLITE_DONE)
                {
                    m_typecodes.push_back(new eTypeCode(topicName, typeName, typeCode));
                    returnedValue = true;
                }
            }
            else
            {
                logError(m_log, "Cannot reset the add statement");
            }
        }
    }

    return returnedValue;
}

bool TypeCodeDB::findTypecode(const char *topicName, const char *typeName)
{
    bool returnedValue = false;
    list<eTypeCode*>::iterator it;

    for(it = m_typecodes.begin(); it != m_typecodes.end(); it++)
    {
        if((*it)->equal(topicName, typeName))
            break;
    }

    if(it != m_typecodes.end())
        returnedValue = true;

    return returnedValue;
}

char* TypeCodeDB::getPrintIDL(RTICdrTypeCode *typeCode)
{
    int fd;
    int pipefds[2];
    int readLen = 0;
    fpos_t pos;
    char *returnedValue = NULL;

    if(typeCode != NULL)
    {
        // Save STDOUT
        fflush(stdout);
        fgetpos(stdout, &pos);
        fd = dup(fileno(stdout));

        // Redirect to pipe.
        pipe(pipefds);
        dup2(pipefds[1], fileno(stdout));
        RTICdrTypeCode_print_IDL(typeCode, 0);
        fflush(stdout);

        if((readLen = read(pipefds[0], m_buffer, 1024)) > -1)
        {
            if(readLen > 0)
                returnedValue = m_buffer;
        }

        close(pipefds[0]);
        close(pipefds[1]);

        // Restore STDOUT
        dup2(fd, fileno(stdout));
        clearerr(stdout);
        fsetpos(stdout, &pos);
    }

    return returnedValue;
}
