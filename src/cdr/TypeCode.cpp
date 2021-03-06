/******************************************************************************************
 * Copyright (c) 2015 eProsima. All rights reserved.
 *
 * This copy of eProsima Non-Intrusive DDS Recorder is licensed to you
 * under the terms described in the DDSRECORDER_LICENSE file included in this distribution.
 *
 *****************************************************************************************/
#include "cdr/TypeCode.h"
#include "cdr/StructTypeCode.h"
#include "cdr/ArrayTypeCode.h"
#include "cdr/EnumTypeCode.h"
#include "cdr/StringTypeCode.h"
#include "cdr/PrimitiveTypeCode.h"
#include "cdr/SequenceTypeCode.h"
#include "cdr/UnionTypeCode.h"
#include "fastcdr/Cdr.h"
#include "fastcdr/exceptions/Exception.h"

#include <stdio.h>

const char* const CLASS_NAME = "TypeCode";

using namespace eprosima;

TypeCode::TypeCode(uint32_t kind) : m_kind(kind)
{
}

TypeCode* TypeCode::deserializeTypeCode(char *cdrTypeCode, uint32_t cdrTypeCodeLength)
{
    const char* const METHOD_NAME = "deserializeTypeCode";
    TypeCode *returnedValue = NULL;

    if(cdrTypeCode != NULL)
    {
        // Create the CDR buffer.
        FastBuffer cdrBuffer(cdrTypeCode, cdrTypeCodeLength);
        Cdr cdr(cdrBuffer, Cdr::DEFAULT_ENDIAN, Cdr::DDS_CDR);
        uint32_t kind = 0;

        try
        {
            cdr >> kind;

            // TODO Check that the DDS middleware is RTI.
            if(kind & 0x80000000)
            {
                // Remove the extra bit.
                kind &= 0x7FFFFFFF;

                switch(kind)
                {
                    case KIND_STRUCT:
                        StructTypeCode *structTC = new StructTypeCode();
                        if(structTC->deserialize(cdr))
                            returnedValue = static_cast<TypeCode*>(structTC);
                        else
                            delete structTC;
                        break;
                }
            }
        }
        catch(exception::Exception &ex) {}
    }
    else
    {
        printf("ERROR<%s::%s>: Bad parameter\n", CLASS_NAME, METHOD_NAME);
    }

    return returnedValue;
}

TypeCode* TypeCode::deserializeTypeCode(Cdr &cdr)
{
    TypeCode *returnedValue = NULL;
    uint32_t kind = 0;

    try
    {
        cdr >> kind;

        // TODO Check that the DDS middleware is RTI.
        if(kind & 0x80000000)
        {
            // Remove the extra bit.
            kind &= 0x7FFFFFFF;

            if(kind == KIND_STRUCT)
            {
                StructTypeCode *structTC = new StructTypeCode();
                if(structTC->deserialize(cdr))
                    returnedValue = static_cast<TypeCode*>(structTC);
                else
                    delete structTC;
            }
            else if(kind == KIND_UNION)
            {
                UnionTypeCode *unionTC = new UnionTypeCode();
                if(unionTC->deserialize(cdr))
                    returnedValue = static_cast<TypeCode*>(unionTC);
                else
                    delete unionTC;
            }
            else if(kind == KIND_ARRAY)
            {
                ArrayTypeCode *arrayTC = new ArrayTypeCode();
                if(arrayTC->deserialize(cdr))
                    returnedValue = static_cast<TypeCode*>(arrayTC);
                else
                    delete arrayTC;
            }
            else if(kind == KIND_SEQUENCE)
            {
                SequenceTypeCode *sequenceTC = new SequenceTypeCode();
                if(sequenceTC->deserialize(cdr))
                    returnedValue = static_cast<TypeCode*>(sequenceTC);
                else
                    delete sequenceTC;
            }
            else if(kind == KIND_ENUM)
            {
                EnumTypeCode *enumTC = new EnumTypeCode();
                if(enumTC->deserialize(cdr))
                    returnedValue = static_cast<TypeCode*>(enumTC);
                else
                    delete enumTC;
            }
            else if(kind == KIND_STRING)
            {
                StringTypeCode *stringTC = new StringTypeCode();
                if(stringTC->deserialize(cdr))
                    returnedValue = static_cast<TypeCode*>(stringTC);
                else
                    delete stringTC;
            }
            else if(kindIsPrimitive(kind))
            {
                PrimitiveTypeCode *primitiveTC = new PrimitiveTypeCode(kind);
                if(primitiveTC->deserialize(cdr))
                    returnedValue = static_cast<TypeCode*>(primitiveTC);
                else
                    delete primitiveTC;
            }
        }
    }
    catch(exception::Exception &ex) {}

    return returnedValue;
}

uint32_t TypeCode::getKind() const
{
    return m_kind;
}

bool eprosima::operator<<(IDLPrinter &printer, const TypeCode *typeCode)
{
    bool returnedValue = false;

    if(typeCode != NULL)
        returnedValue = printer << *typeCode;

    return returnedValue;
}
