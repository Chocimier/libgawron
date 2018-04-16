#ifndef JSONLOADER_H
#define JSONLOADER_H

#include <nlohmann/json.hpp>

#include "Loader.h"

namespace gawron
{

class JsonLoader : public Loader
{
public:
	JsonLoader(const std::string &path);

	std::map<std::string,Message> messages() const override;
	std::map<ParameterValue,std::map<Category,CategoryValue>> categories() const override;
	std::map<Category,std::vector<NumericalCase>> numericalCategories() const override;
	std::map<ParameterValue, std::map<FormName, FormValue> > forms() const override;

private:
	std::pair<std::string,Message> readMessage(const nlohmann::json &json) const;
	std::pair<CategoryValueList,Sentence> readSentence(const nlohmann::json &json) const;
	FormDemand readFormDemand(const nlohmann::json &json) const;
	CategoryDemand readCategoryDemand(const nlohmann::json &json) const;

	nlohmann::json mJson;
};

}

#endif
