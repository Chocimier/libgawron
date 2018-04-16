#include "CategoryDemand.h"

namespace gawron
{

CategoryDemand::CategoryDemand(const Category &category, const ParameterName &parameterName):
    mCategory(category),
    mParameterName(parameterName)
{
}

Category CategoryDemand::category() const
{
	return mCategory;
}

ParameterName CategoryDemand::parameterName() const
{
	return mParameterName;
}

}
