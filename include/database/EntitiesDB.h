/******************************************************************************************
 * Copyright (c) 2015 eProsima. All rights reserved.
 *
 * This copy of eProsima Non-Intrusive DDS Recorder is licensed to you
 * under the terms described in the DDSRECORDER_LICENSE file included in this distribution.
 *
 *****************************************************************************************/
#ifndef _ENTITIESDB_H_
#define _ENTITIESDB_H_

#ifdef __cplusplus

#include <string>
#include <list>

#include <sqlite3.h>
#include "RTPSPacketAnalyzer.h"

namespace eprosima
{
    class eProsimaLog;

    class eEntity
    {
        public:

            eEntity(unsigned int hostId, unsigned int appId,
                    unsigned int instanceId, unsigned int entityId,
                    std::string &topicName, std::string &typeName,
                    bool existsTypecode);

            /**
             * \brief This function returns if the entity is the same.
             *
             * \param guidPrefix prefix of the entity.
             * \param entityId entity identifier
             * \return True if they're equal or false in other case.
             */
            bool equal(unsigned int hostId, unsigned int appId,
                    unsigned int instanceId, unsigned int entityId);

            std::string& getTopicName();
            std::string& getTypeName();
            bool getExistsTypecode();
            void setExistsTypecode(bool e);

        private:

            unsigned int m_hostId;
            unsigned int m_appId;
            unsigned int m_instanceId;
            unsigned int m_entityId;
            std::string m_topicName;
            std::string m_typeName;
            bool m_existsTypecode;
    };

    class EntitiesDB
    {
        public:

            EntitiesDB(eProsimaLog &log, sqlite3 *databaseH);

            ~EntitiesDB();

            bool addEntity(const unsigned int npacket, const struct timeval &wts, std::string &ip_src, std::string &ip_dst,
                    unsigned int hostId, unsigned int appId, unsigned int instanceId,
                    unsigned int readerId, unsigned int writerId, unsigned long long writerSeqNum,
                    struct DDS_Time_t &sourceTmp, unsigned int destHostId,
                    unsigned int destAppId, unsigned int destInstanceId,const unsigned int entity_hostId, const unsigned int entity_appId,
                    const unsigned int entity_instanceId, const unsigned int entityId, int type,
                    std::string &topicName, std::string &typeName, bool existsTypecode);

            eEntity* findEntity(const unsigned int hostId, const unsigned int appId,
                    const unsigned int instanceId, const unsigned int entityId);

        private:

            std::list<eEntity*> m_entities;

            std::list<eEntity*> m_entities_without;

            eProsimaLog &m_log;

            bool m_ready;

            /// Handler of the database.
            sqlite3 *m_databaseH;

            /// Sqlite3 statement used to add typecodes.
            sqlite3_stmt *m_addStmt;
            sqlite3_stmt *m_addMsgStmt;
    };
}

#endif

#endif // _ENTITIESDB_H_
