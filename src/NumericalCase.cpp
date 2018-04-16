#include "NumericalCase.h"

#include <algorithm>
#include <sstream>
#include <regex>
#include <type_traits>

namespace gawron
{

const char NumericalCase::alternativeDelimiter = ',';

NumericalCase::NumericalCase(const CategoryValue &value, const std::string &condition):
    mValue(value),
    mCondition(conditionBuilder(condition))
{
}

bool NumericalCase::match(long long number) const
{
	return mCondition(number);
}

CategoryValue NumericalCase::value() const
{
	return mValue;
}

std::function<bool(long long)> NumericalCase::conditionBuilder(const std::string &condition)
{
	if (condition.find(alternativeDelimiter) != std::string::npos)
	{
		return conditionAlternative(condition);
	}

	if (condition == "any")
	{
		return [](long long){return true;};
	}

	size_t pos = 0;
	long long specified = std::stoll(condition, &pos, 10);
	if (pos == condition.size())
	{
		return [specified](long long n){return n == specified;};
	}

	static const std::basic_regex<char> modularRule(R"-((\d+)n(?:\+(\d+))?)-");
	std::match_results<std::string::const_iterator> match;
	bool matches = std::regex_match(condition, match, modularRule);
	if (matches)
	{
		long long period = std::stoll(match[1]);
		long long remainder = 0;
		if (match[2].length() > 0)
		{
			remainder = std::stoll(match[2]);
		}
		return [period, remainder](long long n){return (n % period) == remainder;};
	}

	return [](long long){return false;};
}

std::function<bool(long long)> NumericalCase::conditionAlternative(const std::string &condition)
{
	std::stringstream stream(condition);
	std::string segment;
	std::vector<std::function<bool(long long)>> tests;
	while (std::getline(stream, segment, alternativeDelimiter))
	{
		tests.push_back(conditionBuilder(segment));
	}
	return [tests](long long n)
	{
		return std::any_of(tests.begin(), tests.end(), [n](const std::function<bool(long long)> &test)
		{
			return test(n);
		});
	};
}

}
