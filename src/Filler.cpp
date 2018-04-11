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
