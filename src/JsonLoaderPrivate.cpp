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

#include "JsonLoaderPrivate.h"

#include <fstream>

namespace gawron
{

JsonLoaderPrivate::JsonLoaderPrivate(const std::string &path)
{
	std::ifstream file(path);
	file >> mJson;
}

std::map<std::string, Message> JsonLoaderPrivate::messages() const
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

std::map<ParameterValue,std::map<Category,CategoryValue>> JsonLoaderPrivate::categories() const
{
	std::map<ParameterValue,std::map<Category,CategoryValue>> result;
	nlohmann::json entities = mJson["categories"]["entities"];
	for (nlohmann::json::iterator eit = entities.begin(); eit != entities.end(); ++eit)
	{
		nlohmann::json categories = eit.value();
		for (nlohmann::json::iterator cit = categories.begin(); cit != categories.end(); ++cit)
		{
			result[{eit.key()}].emplace(Category(cit.key()), CategoryValue(cit.value().get<std::string>()));
		}
	}
	return result;
}

std::map<Category,std::vector<NumericalCase>> JsonLoaderPrivate::numericalCategories() const
{
	std::map<Category,std::vector<NumericalCase>> result;
	nlohmann::json numerical = mJson["categories"]["numerical"];
	for (nlohmann::json::iterator cit = numerical.begin(); cit != numerical.end(); ++cit)
	{
		nlohmann::json array = cit.value();
		for (nlohmann::json::iterator ait = array.begin(); ait != array.end(); ++ait)
		{
			result[Category(cit.key())].emplace_back(CategoryValue((*ait)["value"].get<std::string>()), (*ait)["match"]);
		}
	}
	return result;
}

std::map<ParameterValue,std::map<FormName,FormValue>> JsonLoaderPrivate::forms() const
{
	std::map<ParameterValue,std::map<FormName,FormValue>> result;
	nlohmann::json entities = mJson["forms"]["entities"];
	for (nlohmann::json::iterator eit = entities.begin(); eit != entities.end(); ++eit)
	{
		nlohmann::json categories = eit.value();
		for (nlohmann::json::iterator fit = categories.begin(); fit != categories.end(); ++fit)
		{
			result[ParameterValue(eit.key())].emplace(FormName(fit.key()), FormValue(fit.value().get<std::string>()));
		}
	}
	return result;
}

std::pair<std::string,Message> JsonLoaderPrivate::readMessage(const nlohmann::json &json) const
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

std::pair<CategoryValueList,Sentence> JsonLoaderPrivate::readSentence(const nlohmann::json &json) const
{
	FormDemandList formsDemand;
	nlohmann::json formsJson = json["forms"];
	for (nlohmann::json::iterator it = formsJson.begin(); it != formsJson.end(); ++it)
	{
		FormDemand demand = readFormDemand(*it);
		formsDemand.push_back(demand);
	}
	CategoryValueList fits;
	nlohmann::json fitsJson = json["fits"];
	for (nlohmann::json::iterator it = fitsJson.begin(); it != fitsJson.end(); ++it)
	{
		CategoryValue value(it->get<std::string>());
		fits.push_back(value);
	}
	std::string pattern = json["pattern"];
	Sentence sentence(pattern, formsDemand);
	return {fits, sentence};
}

FormDemand JsonLoaderPrivate::readFormDemand(const nlohmann::json &json) const
{
	ParameterName parameter(json[0].get<std::string>());
	FormName form(json[1].get<std::string>());
	return {parameter, form};
}

CategoryDemand JsonLoaderPrivate::readCategoryDemand(const nlohmann::json &json) const
{
	ParameterName parameter = json["parameter"];
	Category category(json["category"].get<std::string>());
	return {category, parameter};
}

}
