#ifndef NUMERICALCASE_H
#define NUMERICALCASE_H

#include <functional>
#include <string>

#include "Category.h"

namespace gawron
{

class NumericalCase
{
public:
	NumericalCase(const CategoryValue &value, const std::string &condition);

	bool match(long long number) const;
	CategoryValue value() const;

private:
	static std::function<bool(long long)> conditionBuilder(const std::string &condition);
	static std::function<bool(long long)> conditionAlternative(const std::string &condition);

	static const char alternativeDelimiter;

	CategoryValue mValue;
	std::function<bool(long long)> mCondition;
};

}

#endif
