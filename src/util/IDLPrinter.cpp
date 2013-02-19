#include "util/IDLPrinter.h"
#include <algorithm>

using namespace eProsima;

IDLPrinter::IDLPrinter() : m_priority(0), m_currentGlobalPriority(0)
{
}

IDLPrinter::IDLPrinter(IDLPrinter &printer) : m_typePrinters(std::move(printer.m_typePrinters)),
	m_priority(printer.m_currentGlobalPriority), m_currentGlobalPriority(++printer.m_currentGlobalPriority)
{
}

IDLPrinter::IDLPrinter(IDLPrinter &&printer) : m_typePrinters(std::move(printer.m_typePrinters)),
	m_priority(printer.m_priority), m_currentGlobalPriority(printer.m_currentGlobalPriority),
	std::ostringstream(std::move(printer))
{
}

IDLPrinter& IDLPrinter::operator=(IDLPrinter &&printer)
{
	this->m_priority = printer.m_priority;
	this->m_currentGlobalPriority = printer.m_currentGlobalPriority;
	std::swap(std::move(this->m_typePrinters), std::move(printer.m_typePrinters)); 
	std::ostringstream &st = *this;
	st = std::move(printer);
	return *this;
}

bool IDLPrinter::isTypePrinterAndUp(const std::string &typeName)
{
	bool returnedValue = false;
	std::unordered_map<std::string, IDLPrinter>::iterator it = m_typePrinters.find(typeName);

	if(it != m_typePrinters.end())
	{
		(*it).second.m_priority = m_currentGlobalPriority++;
		returnedValue = true;
	}

	return returnedValue;
}

std::string IDLPrinter::str()
{
	static_cast<std::ostringstream&>(*this).str("");
	this->clear();
	std::vector<IDLPrinter> vec;

	for(std::unordered_map<std::string, IDLPrinter>::iterator it = m_typePrinters.begin(); it != m_typePrinters.end(); ++it)
	{
		vec.push_back(std::move((*it).second));
	}
	std::sort(vec.begin(), vec.end());

	for(std::vector<IDLPrinter>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		*this << static_cast<std::ostringstream&>(*it).str();
	}

    return static_cast<std::ostringstream&>(*this).str();
}

bool IDLPrinter::addPrinter(std::string &&typeName, IDLPrinter &&printer)
{
	this->m_currentGlobalPriority = printer.m_currentGlobalPriority;
	std::swap(this->m_typePrinters, printer.m_typePrinters);
	std::pair<std::string, IDLPrinter> pair(std::move(typeName), std::move(printer));
	std::pair<std::unordered_map<std::string, IDLPrinter>::iterator, bool> ret = this->m_typePrinters.insert(std::move(pair));

	return true;
}

bool IDLPrinter::operator<(const IDLPrinter &printer) const
{
	return this->m_priority < printer.m_priority;
}