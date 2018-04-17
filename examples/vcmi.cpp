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

#include "JsonLoader.h"
#include "Translator.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Podaj jako argument ścieżkę pliku z tłumaczeniem" << std::endl;
		std::exit(1);
	}
	gawron::Translator t{gawron::JsonLoader{argv[1]}};
	std::vector<std::array<std::string,2>> hate = {{"efreet","genie"}, {"angel", "devil"}};
	for (auto &couple: hate)
	{
		std::string message = t.translate("{} hate {}", {
						{"hater", couple[0]},
						{"hated", couple[1]},
					});
		std::cout << message << std::endl;
		message = t.translate("{} hate {}", {
						{"hater", couple[1]},
						{"hated", couple[0]},
					});
		std::cout << message << std::endl;
	}
}
