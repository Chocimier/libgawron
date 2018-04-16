#include "Message.h"

namespace gawron
{

Message::Message(const std::vector<std::pair<CategoryValueList,Sentence>> &sentences, const CategoryDemandList &categoriesDemand):
    mCategoryDemandList(categoriesDemand),
    mSentences(sentences)
{
}

Sentence Message::selectSentence(const CategoryValueList &categories) const
{
	for (auto &pair: mSentences)
	{
		if (pair.first == categories)
		{
			return pair.second;
		}
	}
	return {"", {}};
}

CategoryDemandList Message::categoryDemandList() const
{
	return mCategoryDemandList;
}

}
