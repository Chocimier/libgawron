list(APPEND examples
	arrive
	animals
	vcmi
)

foreach(example ${examples})
	add_executable(${example} ${example}.cpp)
	set_property(TARGET ${example} PROPERTY CXX_STANDARD 11)
	target_link_libraries(${example} LINK_PUBLIC gawron)
endforeach(example)
