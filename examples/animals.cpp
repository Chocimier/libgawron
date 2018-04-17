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

#include <iostream>
#include <string>

#include "JsonLoader.h"
#include "Translator.h"

std::string lang_file(const std::string &lang, const std::string &directory)
{
	std::string filename("animals_$.json");
	size_t blank = filename.find('$');
	return directory + "/" + filename.replace(blank, 1, lang);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Podaj jako argument ścieżkę katalogu z tłumaczeniami" << std::endl;
		std::exit(1);
	}
	std::array<gawron::Translator,4> translators{
		gawron::Translator{gawron::JsonLoader{lang_file("pl", argv[1])}},
		gawron::Translator{gawron::JsonLoader{lang_file("de", argv[1])}},
		gawron::Translator{gawron::JsonLoader{lang_file("ru", argv[1])}},
		gawron::Translator{gawron::JsonLoader{lang_file("en", argv[1])}},
	};
	std::vector<std::string> figure{"tall", "short", "skinny", "fat"};
	std::vector<std::string> color{"gray", "black", "brown", "white"};
	std::vector<std::string> animal{"cat", "dog", "cow", "pig"};
	for (size_t i=0; i<4; ++i)
	{
		for (gawron::Translator &t: translators)
		{
			std::string message = t.translate("{figure} {color} {animal}", {
							{"animal", {animal[i]}},
							{"color", {color[i]}},
							{"figure", {figure[i]}},
						});
			std::cout << message << std::endl;
		}
		std::cout << std::endl;
	}
}
