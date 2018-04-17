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
