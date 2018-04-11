#include "Translator.h"

#include <istream>

#include "Parameter.h"

namespace gawron
{

Translator::Translator(const std::string &file):
	mCategoriesManager(file),
	mFormsManager(file)
{
	mMessages = {
		{"{n} {creatures} arrived.", Message{
			 {
				  {
					  {"mos", "lz"}, Sentence{
						 "{} nie przybyli",
						 { FormDemand{"creatures","MMn"} }
					 },
				  },
				  {
					  {"ż", "lz"}, Sentence{
						 "{} nie przybyły",
						 { FormDemand{"creatures","MMn"} }
					 },
				  },
				  {
					  {"n", "lz"}, Sentence{
						 "{} nie przybyły",
						 { FormDemand{"creatures","MMn"} }
					 },
				  },
				{
					 {"mos", "lp"},Sentence{
					 "Przybył {}",
					{FormDemand{"creatures", "MP"}}}
				},
				{
					{"ż", "lp"},Sentence{
					 "Przybyła {}",
					{FormDemand{"creatures", "MP"}}}
				},
				{
					{"n", "lp"},Sentence{
					 "Przybyło {}",
					{FormDemand{"creatures", "MP"}}}
				},
				{
					{"mos", "lps"},Sentence{
					 "Przybyli {} {}",
					FormDemandList{FormDemand{"n", "liczba"}, FormDemand{"creatures", "MMn"}}}
				},
				{
					{"ż", "lps"},Sentence{
					 "Przybyły {} {}",
					{FormDemand{"n", "liczba"}, {"creatures", "MMn"}}}
				},
				{
					{"n", "lps"},Sentence{
					 "Przybyły {} {}",
					{FormDemand{"n", "liczba"}, {"creatures", "MMn"}}}
				},
				{
					{"mos", "lmn"},Sentence{
					 "Przybyło {} {}",
					{FormDemand{"n", "liczba"}, {"creatures", "DMn"}}}
				},
				{
					{"ż", "lmn"},Sentence{
					 "Przybyło {} {}",
					{FormDemand{"n", "liczba"}, {"creatures", "DMn"}}}
				},
				{
					{"n", "lmn"},Sentence{
					 "Przybyło {} {}",
					{FormDemand{"n", "liczba"}, {"creatures", "DMn"}}}
				}
			 },
			 {
				  CategoryDemand{"rodzaj","creatures"},
				  CategoryDemand{"liczba","n"}
			  }}
		 }
		};
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
