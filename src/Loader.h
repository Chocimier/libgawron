#ifndef LOADER_H
#define LOADER_H

#include <Category.h>
#include <Message.h>
#include <NumericalCase.h>
#include <Parameter.h>

namespace gawron
{

class Loader
{
public:
	virtual std::map<std::string,Message> messages() const = 0;
	virtual std::map<ParameterValue,std::map<Category,CategoryValue>> categories() const = 0;
	virtual std::map<Category,std::vector<NumericalCase>> numericalCategories() const = 0;
	virtual std::map<ParameterValue,std::map<FormName,FormValue>> forms() const = 0;
};

}

#endif
