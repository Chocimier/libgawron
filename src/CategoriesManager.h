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

#ifndef CATEGORIESMANAGER_H
#define CATEGORIESMANAGER_H

#include <map>
#include <vector>

#include "Loader.h"

namespace gawron
{

class CategoriesManager
{
public:
	explicit CategoriesManager(const Loader &loader);

	CategoryValueList categories(const CategoryDemandList &categoriesDemand, const Parameters &parameters);
	CategoryValue numericalCategory(const Category &category, const ParameterValue &parameter);

private:
	std::map<ParameterValue,std::map<Category,CategoryValue>> mCategoryValues;
	std::map<Category,std::vector<NumericalCase>> mNumericalCategories;
};

}

#endif
