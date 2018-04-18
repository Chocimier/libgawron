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

#ifndef FORM_H
#define FORM_H

#include <string>
#include <vector>

namespace gawron
{

class FormName
{
public:
	explicit FormName(const std::string &form);

	friend bool operator <(const FormName &lhs, const FormName &rhs);
	friend bool operator ==(const FormName &lhs, const FormName &rhs);

private:
	std::string mFormName;
};

class FormValue
{
public:
	explicit FormValue(const std::string &form);

	explicit operator std::string() const;
	friend bool operator <(const FormValue &lhs, const FormValue &rhs);
	friend bool operator ==(const FormValue &lhs, const FormValue &rhs);

private:
	std::string mFormValue;
};

using FormList = std::vector<FormValue>;

}

#endif
