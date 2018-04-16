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
