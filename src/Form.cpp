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

#include "Form.h"

namespace gawron
{

FormName::FormName(const std::string &form):
	mFormName(form)
{
}

bool operator <(const gawron::FormName &lhs, const gawron::FormName &rhs)
{
	return lhs.mFormName < rhs.mFormName;
}

bool operator ==(const gawron::FormName &lhs, const gawron::FormName &rhs)
{
	return lhs.mFormName == rhs.mFormName;
}

FormValue::FormValue(const std::string &form):
	mFormValue(form)
{
}

FormValue::operator std::string() const
{
	return mFormValue;
}


bool operator <(const gawron::FormValue &lhs, const gawron::FormValue &rhs)
{
	return lhs.mFormValue < rhs.mFormValue;
}

bool operator ==(const gawron::FormValue &lhs, const gawron::FormValue &rhs)
{
	return lhs.mFormValue == rhs.mFormValue;
}

}
