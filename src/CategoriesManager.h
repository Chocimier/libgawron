#ifndef CATEGORIESMANAGER_H
#define CATEGORIESMANAGER_H

#include <map>
#include <vector>

#include "Category.h"
#include "CategoryDemand.h"
#include "Loader.h"
#include "NumericalCase.h"
#include "Parameter.h"

namespace gawron
{

class CategoriesManager
{
public:
	CategoriesManager(const Loader &path);

	CategoryList categories(const CategoryDemandList &categoriesDemand, const Parameters &parameters);
	CategoryValue numericalCategory(const Category &category, const ParameterValue &parameter);

private:
	std::map<ParameterValue,std::map<Category,CategoryValue>> mCategoryValues;
	std::map<Category,std::vector<NumericalCase>> mNumericalCategories;
};

}

#endif
