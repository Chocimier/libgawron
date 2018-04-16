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
