#ifndef PARAMETER_H
#define PARAMETER_H

#include <map>
#include <string>

namespace gawron
{

using ParameterName = std::string;

class ParameterValue
{
public:
	enum class Type
	{
		String,
		Number
	};

	ParameterValue(const std::string &string);
	ParameterValue(long long number);

	Type type() const;
	std::string string() const;
	long long number() const;

	operator std::string() const;

private:
	std::string mString;
	long long mNumber;
	Type mType;
};

bool operator <(const gawron::ParameterValue &lhs, const gawron::ParameterValue &rhs);

using Parameters = std::map<ParameterName,ParameterValue>;

}

#endif
