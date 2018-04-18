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

#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>

#include "Parameter.h"

namespace gawron
{

class CategoryValue
{
public:
	explicit CategoryValue(const std::string &value);

	friend bool operator <(const CategoryValue &lhs, const CategoryValue &rhs);
	friend bool operator ==(const CategoryValue &lhs, const CategoryValue &rhs);

private:
	std::string mValue;
};


using CategoryValueList = std::vector<CategoryValue>;

class Category
{
public:
	explicit Category(const std::string &category);

	friend bool operator <(const Category&lhs, const Category &rhs);
	friend bool operator ==(const Category&lhs, const Category &rhs);

private:
	std::string mCategory;
};


using CategoryList = std::vector<Category>;

}

#endif
