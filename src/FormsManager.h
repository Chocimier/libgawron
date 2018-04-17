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

#ifndef FORMSMANAGER_H
#define FORMSMANAGER_H

#include <map>
#include <string>

#include "Loader.h"

namespace gawron
{

class FormsManager
{
public:
	explicit FormsManager(const Loader &loader);

	FormList forms(const FormDemandList &formsDemand, const Parameters &parameters);

private:
	std::map<ParameterValue,std::map<FormName,FormValue>> mForms;
};

}

#endif
