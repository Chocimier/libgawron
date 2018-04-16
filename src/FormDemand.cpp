#include "FormDemand.h"

namespace gawron
{

FormDemand::FormDemand(const ParameterName &parameterName, const FormName &formName):
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