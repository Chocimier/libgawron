#include "Sentence.h"

namespace gawron
{

Sentence::Sentence(const std::string &pattern, const FormDemandList &formsDemand):
	mPattern(pattern),
    mFormsDemand(formsDemand)
{
}

std::string Sentence::pattern() const
{
	return mPattern;
}

FormDemandList Sentence::formsDemand() const
{
	return mFormsDemand;
}

}
