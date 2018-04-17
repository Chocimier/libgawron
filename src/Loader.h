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

#ifndef LOADER_H
#define LOADER_H

#include <Category.h>
#include <Message.h>
#include <NumericalCase.h>
#include <Parameter.h>

namespace gawron
{

class Loader
{
public:
	virtual std::map<std::string,Message> messages() const = 0;
	virtual std::map<ParameterValue,std::map<Category,CategoryValue>> categories() const = 0;
	virtual std::map<Category,std::vector<NumericalCase>> numericalCategories() const = 0;
	virtual std::map<ParameterValue,std::map<FormName,FormValue>> forms() const = 0;
};

}

#endif
