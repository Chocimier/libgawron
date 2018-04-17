/*
 * Copyright 2018 Piotr Wojcik <chocimier@tlen.pl>
 *
 * This file is part of libgawron.
 *
 * Libgawron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Libgawron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libgawron. If not, see <http://www.gnu.org/licenses/>.
 */

#include "JsonLoader.h"

#include <fstream>

namespace gawron
{

JsonLoader::JsonLoader(const std::string &path)
{
	std::ifstream file(path);
	file >> mJson;
}

std::map<std::string, Message> JsonLoader::messages() const
{
	nlohmann::json messages = mJson["messages"];
	std::map<std::string, Message> result;
	for (nlohmann::json::iterator it = messages.begin(); it != messages.end(); ++it)
	{
		std::pair<std::string,Message> message = readMessage(*it);
		result.insert(message);
	}
	return result;
}

std::map<ParameterValue,std::map<Category,CategoryValue>> JsonLoader::categories() const
{
	std::map<ParameterValue,std::map<Category,CategoryValue>> result;
	nlohmann::json entities = mJson["categories"]["entities"];
	for (nlohmann::json::iterator eit = entities.begin(); eit != entities.end(); ++eit)
	{
		nlohmann::json categories = eit.value();
		for (nlohmann::json::iterator cit = categories.begin(); cit != categories.end(); ++cit)
		{
			result[{eit.key()}].emplace(cit.key(), cit.value().get<std::string>());
		}
	}
	return result;
}

std::map<Category,std::vector<NumericalCase>> JsonLoader::numericalCategories() const
{
	std::map<Category,std::vector<NumericalCase>> result;
	nlohmann::json numerical = mJson["categories"]["numerical"];
	for (nlohmann::json::iterator cit = numerical.begin(); cit != numerical.end(); ++cit)
	{
		nlohmann::json array = cit.value();
		for (nlohmann::json::iterator ait = array.begin(); ait != array.end(); ++ait)
		{
			result[{cit.key()}].emplace_back((*ait)["value"], (*ait)["match"]);
		}
	}
	return result;
}

std::map<gawron::ParameterValue,std::map<gawron::FormName,gawron::FormValue>> gawron::JsonLoader::forms() const
{
	std::map<gawron::ParameterValue,std::map<gawron::FormName,gawron::FormValue>> result;
	nlohmann::json entities = mJson["forms"]["entities"];
	for (nlohmann::json::iterator eit = entities.begin(); eit != entities.end(); ++eit)
	{
		nlohmann::json categories = eit.value();
		for (nlohmann::json::iterator fit = categories.begin(); fit != categories.end(); ++fit)
		{
			result[{eit.key()}].emplace(fit.key(), fit.value());
		}
	}
	return result;
}

std::pair<std::string,Message> JsonLoader::readMessage(const nlohmann::json &json) const
{
	nlohmann::json sentencesJson = json["sentences"];
	std::vector<std::pair<CategoryValueList,Sentence>> sentences;
	for (nlohmann::json::iterator it = sentencesJson.begin(); it != sentencesJson.end(); ++it)
	{
		sentences.push_back(readSentence(*it));
	}
	nlohmann::json categoriesJson = json["categories"];
	CategoryDemandList categoriesDemand;
	for (nlohmann::json::iterator it = categoriesJson.begin(); it != categoriesJson.end(); ++it)
	{
		categoriesDemand.push_back(readCategoryDemand(*it));
	}
	Message message(sentences, categoriesDemand);
	std::string id = json["id"];
	return {id, message};
}

std::pair<CategoryValueList,Sentence> JsonLoader::readSentence(const nlohmann::json &json) const
{
	FormDemandList formsDemand;
	nlohmann::json formsJson = json["forms"];
	for (nlohmann::json::iterator it = formsJson.begin(); it != formsJson.end(); ++it)
	{
		FormDemand demand = readFormDemand(*it);
		formsDemand.push_back(demand);
	}
	CategoryValueList fits = json["fits"];
	std::string pattern = json["pattern"];
	Sentence sentence(pattern, formsDemand);
	return {fits, sentence};
}

FormDemand JsonLoader::readFormDemand(const nlohmann::json &json) const
{
	ParameterName parameter = json[0];
	FormName form = json[1];
	return {parameter, form};
}

CategoryDemand JsonLoader::readCategoryDemand(const nlohmann::json &json) const
{
	ParameterName parameter = json["parameter"];
	Category category = json["category"];
	return {category, parameter};
}

}
