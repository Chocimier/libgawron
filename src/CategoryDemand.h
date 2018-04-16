#ifndef CATEGORYDEMAND_H
#define CATEGORYDEMAND_H

#include <vector>

#include "Category.h"
#include "Parameter.h"

namespace gawron
{

class CategoryDemand
{
public:
	CategoryDemand(const Category &category, const ParameterName &parameterName);

	Category category() const;
	ParameterName parameterName() const;

private:
	Category mCategory;
	ParameterName mParameterName;
};

using CategoryDemandList = std::vector<CategoryDemand>;

}

#endif
