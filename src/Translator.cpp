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

#include "Translator.h"

#include <iostream>

#include "Parameter.h"

namespace gawron
{

Translator::Translator(const Loader &loader):
	mMessages(loader.messages()),
	mCategoriesManager(loader),
	mFormsManager(loader)
{
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
