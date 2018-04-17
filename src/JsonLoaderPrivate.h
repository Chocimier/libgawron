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

#ifndef JSONLOADERPRIVATE_H
#define JSONLOADERPRIVATE_H

#include <nlohmann/json.hpp>

#include "Loader.h"

namespace gawron
{

class JsonLoaderPrivate : public Loader
{
public:
	explicit JsonLoaderPrivate(const std::string &path);

	std::map<std::string,Message> messages() const override;
	std::map<ParameterValue,std::map<Category,CategoryValue>> categories() const override;
	std::map<Category,std::vector<NumericalCase>> numericalCategories() const override;
	std::map<ParameterValue,std::map<FormName,FormValue>> forms() const override;

private:
	std::pair<std::string,Message> readMessage(const nlohmann::json &json) const;
	std::pair<CategoryValueList,Sentence> readSentence(const nlohmann::json &json) const;
	FormDemand readFormDemand(const nlohmann::json &json) const;
	CategoryDemand readCategoryDemand(const nlohmann::json &json) const;

	nlohmann::json mJson;
};

}

#endif
