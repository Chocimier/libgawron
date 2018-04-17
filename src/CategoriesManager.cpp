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

#include "CategoriesManager.h"

#include <cassert>
#include <string>

#include "CategoryDemand.h"

namespace gawron
{

CategoriesManager::CategoriesManager(const Loader &loader):
	mCategoryValues(loader.categories()),
	mNumericalCategories(loader.numericalCategories())
{
}

CategoryList CategoriesManager::categories(const CategoryDemandList &categoriesDemand, const Parameters &parameters)
{
	CategoryList result;
	for (CategoryDemand demand: categoriesDemand)
	{
		ParameterValue parameter = parameters.at(demand.parameterName());
		if (parameter.type() == ParameterValue::Type::Number)
		{
			result.push_back(numericalCategory(demand.category(), parameter));
		}
		else
		{
			result.push_back(mCategoryValues.at(parameter.string()).at(demand.category()));
		}
	}

	return result;
}

CategoryValue CategoriesManager::numericalCategory(const Category &category, const ParameterValue &parameter)
{
	auto &cases = mNumericalCategories.at(category);
	for (NumericalCase &numCase: cases)
	{
		if (numCase.match(parameter.number()))
		{
			return numCase.value();
		}
	}
	assert(false);
	return "";
}

}
