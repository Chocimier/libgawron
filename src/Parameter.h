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
