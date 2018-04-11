#ifndef MESSAGE_H
#define MESSAGE_H

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "Category.h"
#include "CategoryDemand.h"
#include "Sentence.h"

namespace gawron
{

class Message
{
public:
	Message(const std::vector<std::pair<CategoryValueList,Sentence>> &sentences, const CategoryDemandList &categoriesDemand);

	Sentence selectSentence(const CategoryValueList &categories) const;
	CategoryDemandList categoryDemandList() const;

private:
	CategoryDemandList mCategoryDemandList;
	std::vector<std::pair<CategoryValueList,Sentence>> mSentences;
};

}

#endif
