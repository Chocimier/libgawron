/*
 * Copyright 2018 Piotr Wojcik <chocimier@tlen.pl>
 *
 * This file is part of libgawron.
 *
 * Libgawron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Libgawron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libgawron. If not, see <http://www.gnu.org/licenses/>.
 */

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
