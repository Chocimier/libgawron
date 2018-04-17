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

#include "JsonLoaderPrivate.h"

namespace gawron
{

JsonLoader::JsonLoader(const std::string &path):
	pImpl(new JsonLoaderPrivate(path))
{
}

JsonLoader::~JsonLoader()
{
	delete pImpl;
}

std::map<std::string, Message> JsonLoader::messages() const
{
	return pImpl->messages();
}

std::map<ParameterValue,std::map<Category,CategoryValue>> JsonLoader::categories() const
{
	return pImpl->categories();
}

std::map<Category,std::vector<NumericalCase>> JsonLoader::numericalCategories() const
{
	return pImpl->numericalCategories();
}

std::map<ParameterValue,std::map<FormName,FormValue>> JsonLoader::forms() const
{
	return pImpl->forms();
}

}
