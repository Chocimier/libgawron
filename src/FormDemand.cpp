#include "FormDemand.h"

namespace gawron
{

FormDemand::FormDemand(const std::string &parameterName, const std::string &formName):
    mFormName(formName),
    mParameterName(parameterName)
{
}

FormName FormDemand::formName() const
{
	return mFormName;
}

ParameterName FormDemand::parameterName() const
{
	return mParameterName;
}

}
