#ifndef FORMDEMAND_H
#define FORMDEMAND_H

#include <string>
#include <vector>

#include "Form.h"
#include "Parameter.h"

namespace gawron
{

class FormDemand
{
public:
	FormDemand(const ParameterName &parameterName, const FormName &formName);

	FormName formName() const;
	ParameterName parameterName() const;

private:
	FormName mFormName;
	ParameterName mParameterName;
};

using FormDemandList = std::vector<FormDemand>;

}

#endif
