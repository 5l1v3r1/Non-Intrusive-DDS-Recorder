#include "cdr/StringTypeCode.h"
#include "util/IDLPrinter.h"
#include "Cdr.h"

using namespace eProsima;

bool StringTypeCode::deserialize(CDR &cdr)
{
    return (cdr >> m_dump) & (cdr >> m_maxLength);
}

bool eProsima::operator<<(IDLPrinter &printer, const StringTypeCode &typeCode)
{
    return printer << "string ";
}

bool eProsima::operator<<(IDLPrinter &printer, const StringTypeCode *typeCode)
{
    bool returnedValue = false;

    if(typeCode != NULL)
        returnedValue = printer << *typeCode;

    return returnedValue;
}
