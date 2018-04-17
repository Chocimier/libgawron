/*
 * Copyright 2018 Piotr Wojcik <chocimier@tlen.pl>
 *
 * This file is part of libgawron.
 *
 * Libgawron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Libgawron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libgawron. If not, see <http://www.gnu.org/licenses/>.
 */

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
