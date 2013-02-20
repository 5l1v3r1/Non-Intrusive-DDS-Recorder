#include "cdr/ContentTypeCode.h"

#include <stdio.h>

using namespace eProsima;

ContentTypeCode::ContentTypeCode(uint32_t kind) : TypeCode(kind),
    m_contentTypeCode(NULL)
{
}

ContentTypeCode::~ContentTypeCode()
{
    if(m_contentTypeCode != NULL)
        delete m_contentTypeCode;
}

const TypeCode* ContentTypeCode::getContentTypeCode() const
{
    return m_contentTypeCode;
}

bool ContentTypeCode::deserializeContent(CDR &cdr)
{
    return (m_contentTypeCode = TypeCode::deserializeTypeCode(cdr)) != NULL;
}