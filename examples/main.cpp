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
		std::cout << "Podaj ścieżkę pliku z tłumaczeniem" << std::endl;
		std::exit(1);
	}
	std::vector<std::string> creatures = {"orc", "vyvern", "kopytko"};
	std::vector<int> counts = {0, 1, 2, 12, 102, 5};
	gawron::Translator t(gawron::JsonLoader{argv[1]});
	for (int n: counts)
	{
		for (std::string &creature: creatures)
		{
			std::string message = t.translate("{n} {creatures} arrived.", {
							{"creatures", {creature}},
							{"n", {n}}
						});
			std::cout << message << std::endl;
		}
	}
}
