#ifndef FORMSMANAGER_H
#define FORMSMANAGER_H

#include <map>
#include <string>

#include "Form.h"
#include "FormDemand.h"
#include "Loader.h"
#include "Parameter.h"

namespace gawron
{

class FormsManager
{
public:
	FormsManager(const Loader &loader);

	FormList forms(const FormDemandList &formsDemand, const Parameters &parameters);

private:
	std::map<ParameterValue, std::map<FormName, FormValue>> mForms;
};

}

#endif
