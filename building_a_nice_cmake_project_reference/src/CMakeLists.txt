target_include_directories(my_project PRIVATE component)

set( SOURCES
	main.cpp
	component/function.cpp)

message(SOURCES="${SOURCES}")
target_sources(my_project PRIVATE ${SOURCES})


