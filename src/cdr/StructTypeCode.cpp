/******************************************************************************************
 * Copyright (c) 2015 eProsima. All rights reserved.
 *
 * This copy of eProsima Non-Intrusive DDS Recorder is licensed to you
 * under the terms described in the DDSRECORDER_LICENSE file included in this distribution.
 *
 *****************************************************************************************/
#include "cdr/StructTypeCode.h"
#include "util/IDLPrinter.h"
#include "fastcdr/Cdr.h"
#include "fastcdr/exceptions/Exception.h"

#include "cdr/TypeCodeCopy.h"
using namespace eprosima;


#include <iostream>

StructMember::StructMember(std::string &name, uint16_t bits, uint8_t flags) : Member(name),
    m_bits(bits), m_flags(flags)
{
}

StructMember::StructMember(const StructMember& copy):m_bits(0),m_flags(0)
{
	std::string name = copy.getName();
	this->setName(name);
	TypeCode* TC = TypeCodeCopy::copy(copy.getTypeCode());
	this->setTypeCode(TC);
}

StructTypeCode::StructTypeCode() : MemberedTypeCode(TypeCode::KIND_STRUCT)
{
}

StructTypeCode::StructTypeCode(const StructTypeCode& copy): MemberedTypeCode(TypeCode::KIND_STRUCT)
{
	for(std::vector<Member*>::const_iterator it = copy.m_members.begin();it!= copy.m_members.end();++it)
	{
		StructMember* sM = (StructMember*)(*it);
		sM = new StructMember(*sM);
		m_members.push_back(sM);
	}
	m_name = copy.m_name;
	m_memberCount = copy.m_memberCount;

}

bool StructTypeCode::deserialize(Cdr &cdr)
{
    bool returnedValue = true;
    uint16_t size = 0;

    try
    {
        // Deserialize size.
        cdr >> size;
        returnedValue &= deserializeName(cdr);
        returnedValue &= deserializeMembers(cdr);
    }
    catch(exception::Exception &ex)
    {
        returnedValue = false;
    }

    return returnedValue;
}

Member* StructTypeCode::deserializeMemberInfo(std::string name, Cdr &cdr)
{
    Member *returnedValue = NULL;
    uint8_t mPointer = 0;
    uint16_t bits = 0;
    uint8_t flags = 0;

    try
    {
        cdr >> mPointer;
        cdr >> bits;
        cdr >> flags;
        returnedValue = new StructMember(name, bits, flags);
    }
    catch(exception::Exception &ex) {}

    return returnedValue;
}

bool StructTypeCode::print(IDLPrinter &printer, bool write) const
{
    bool returnedValue = true;

	if(write)
		printer.getOut() << getName();

    if(!printer.isTypePrinterAndUp("struct " + getName()))
    {
			IDLPrinter *tPrinter = new IDLPrinter(printer);
			tPrinter->getOut() << "struct " << getName() << " {" << std::endl;
        
			for(uint32_t count = 0; count < getMemberCount(); ++count)
			{
				const StructMember *member = dynamic_cast<const StructMember*>(getMember(count));

				if(member != NULL)
				{
					tPrinter->getOut() << "   ";
					returnedValue &= *tPrinter << member->getTypeCode();
					tPrinter->getOut() << " " << member->getName() << ";" << std::endl;
				}
				else
					returnedValue = false;
			}

			tPrinter->getOut() << "};" << std::endl << std::endl;
			printer.addPrinter("struct " + getName(), tPrinter);
    }
	else
	{
		for(uint32_t count = 0; count < getMemberCount(); ++count)
		{
			const StructMember *member = dynamic_cast<const StructMember*>(getMember(count));

			if(member != NULL)
			{
				returnedValue &= member->getTypeCode()->print(printer, false);
			}
			else
				returnedValue = false;
		}
	}

    return returnedValue;
}

bool StructTypeCode::addMember(StructMember* m)
{
	if(isMemberWithName(m->getName()))
		return false;
	this->addMemberPtr((Member*)m);
	return true;
}

bool eprosima::operator<<(IDLPrinter &printer, const StructTypeCode *typeCode)
{
    bool returnedValue = false;

    if(typeCode != NULL)
        returnedValue = printer << *typeCode;

    return returnedValue;
}
