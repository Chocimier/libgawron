#include "FormsManager.h"

namespace gawron
{

FormsManager::FormsManager(const std::string &file)
{
	mForms = {
		{{"orc"}, {
			 { "MP", "ork" },
			 { "MMn", "orkowie" },
			 { "DMn", "orków" }
		 }},
		{{"vyvern"}, {
			{"MP", "wiwerna"},
			{"MMn", "wiwerny"},
			{"DMn", "wiwern"}
		}},
		{{"kopytko"}, {
			{"MP", "kopytko"},
			{"MMn", "kopytka"},
			{"DMn", "kopytek"}
		}}
	};
}

FormList FormsManager::forms(const FormDemandList &formsDemand, const Parameters &parameters)
{
	FormList result;
	for (FormDemand demand: formsDemand)
	{
		ParameterValue parameter = parameters.at(demand.parameterName());
		if (parameter.type() == ParameterValue::Type::String)
		{
			result.push_back(mForms.at(parameter).at(demand.formName()));
		}
		else
		{
			result.push_back(std::to_string(parameter.number()));
		}
	}
	return result;
}

}
