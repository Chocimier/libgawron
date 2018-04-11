#ifndef FILLER_H
#define FILLER_H

#include <string>

#include "Form.h"
#include "Sentence.h"

namespace gawron
{

class Filler
{
public:
	std::string fill(const Sentence &sentence, const FormList &forms);
};

}

#endif
