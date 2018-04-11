#include <iostream>

#include "Translator.h"

int main()
{
	std::vector<std::string> creatures = {"orc", "vyvern", "kopytko"};
	std::vector<int> counts = {0, 1, 2, 12, 102, 5};
	gawron::Translator t("");
	for (int n: counts){
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
