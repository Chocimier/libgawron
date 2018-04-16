#include "Translator.h"

#include <iostream>

#include "Parameter.h"

namespace gawron
{

Translator::Translator(const Loader &loader):
	mCategoriesManager(loader),
	mFormsManager(loader)
{
	mMessages = loader.messages();
}

std::string Translator::translate(const std::string &message_id, const Parameters &parameters)
{
	Message message = mMessages.at(message_id);
	CategoryDemandList categoriesDemand = message.categoryDemandList();
	CategoryList categories = mCategoriesManager.categories(categoriesDemand, parameters);
	Sentence sentence = message.selectSentence(categories);
	FormDemandList formsDemand = sentence.formsDemand();
	FormList forms = mFormsManager.forms(formsDemand, parameters);
	return mFiller.fill(sentence, forms);
}

}
