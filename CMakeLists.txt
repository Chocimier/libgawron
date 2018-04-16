cmake_minimum_required(VERSION 2.8)

set(project_name gawron)
project(${project_name})

set(project_src
	src/CategoriesManager.cpp
	src/CategoryDemand.cpp
	src/Filler.cpp
	src/FormDemand.cpp
	src/FormsManager.cpp
	src/JsonLoader.cpp
	src/Message.cpp
	src/NumericalCase.cpp
	src/Parameter.cpp
	src/Sentence.cpp
	src/Translator.cpp
)

include_directories(src)
include_directories(SYSTEM thirdparty)

add_library(${project_name} SHARED ${project_src})
set_property(TARGET ${project_name} PROPERTY CXX_STANDARD 11)

add_subdirectory(examples)