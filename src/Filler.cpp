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

#include "Filler.h"

namespace gawron
{

std::string Filler::fill(const Sentence &sentence, const FormList &forms)
{
	size_t formsPosition = 0;
	const std::string pattern = sentence.pattern();
	std::string result;
	for(size_t i = 0; i < pattern.size(); ++i)
	{
		if (pattern[i] == '}')
		{
			result += '}';
			++i;
		}
		if (pattern[i] != '{')
		{
			result += pattern[i];
		}
		else if (i+1 < pattern.size() && pattern[i+1] == '{')
		{
			result += pattern[i];
			++i;
		}
		else
		{
			result += forms[formsPosition];
			++formsPosition;
			++i;
		}
	}
	return result;
}

}
