#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <map>
#include <string>

#include "CategoriesManager.h"
#include "Filler.h"
#include "FormsManager.h"
#include "Loader.h"
#include "Message.h"

namespace gawron
{

class Translator
{
public:
	Translator(const Loader &loader);
	std::string translate(const std::string &message_id, const Parameters &parameters);

private:
	std::map<std::string, Message> mMessages;
	CategoriesManager mCategoriesManager;
	FormsManager mFormsManager;
	Filler mFiller;
};

}

#endif
