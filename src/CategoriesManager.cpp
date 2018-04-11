#include "CategoriesManager.h"

#include <string>

#include "CategoryDemand.h"

namespace gawron
{

CategoriesManager::CategoriesManager(const std::string &path)
{
	mCategoryValues = {
		{ ParameterValue{"orc"},
			{
				{"rodzaj", CategoryValue{"mos"}}
		 	}
		},
		{ ParameterValue{"vyvern"},
			{
				{"rodzaj", CategoryValue{"ż"}}
		 	}
		},
		{ ParameterValue{"kopytko"},
			{
				{"rodzaj", CategoryValue{"n"}}
		 	}
		}
	};
		mNumericalCategories = {
			{"liczba", {
				NumericalCase{"lz", "0"},
				{"lp", "1"},
				{"lmn", "100n+12,100n+13,100n+14"},
				{"lps", "10n+2,10n+3,10n+4"},
				{"lmn", "any"}
			}}
		};
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
}

}
