#include "Message.h"

namespace gawron
{

ParameterValue::ParameterValue(const std::string &string):
	mString(string),
    mNumber(0),
    mType(Type::String)
{
}

ParameterValue::ParameterValue(long long number):
    mNumber(number),
    mType(Type::Number)
{
}

ParameterValue::Type ParameterValue::type() const
{
	return mType;
}

std::string ParameterValue::string() const
{
	return mString;
}

long long ParameterValue::number() const
{
	return mNumber;
}

ParameterValue::operator std::string() const
{
	return string();
}

bool operator <(const ParameterValue &lhs, const ParameterValue &rhs)
{
	if (lhs.type() < rhs.type())
	{
		return true;
	}
	switch (lhs.type())
	{
		case gawron::ParameterValue::Type::String:
			return lhs.string() < rhs.string();
		case gawron::ParameterValue::Type::Number:
			return lhs.number() < rhs.number();
		default:
			return false;
	}
}

}
