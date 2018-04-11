#ifndef SENTENCE_H
#define SENTENCE_H

#include <string>

#include "Form.h"
#include "FormDemand.h"

namespace gawron
{

class Sentence
{
public:
	Sentence(const std::string &pattern, const FormDemandList &formsDemand);

	std::string pattern() const;
	FormDemandList formsDemand() const;

private:
	std::string mPattern;
	FormDemandList mFormsDemand;
};

}

#endif
