
cmake_minimum_required(VERSION 3.15)
project(my_project)

set(CMAKE_CXX_STANDARD 11)
#TODO: make debug option
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O0")

## Check system and configure accordingly
if(UNIX)
  message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
  message("This is a windows system")
endif()

## Enable Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
	# set input and outputs
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

	#request to configure file
	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
	message("Doxygen build started")

	add_custom_target( doc_doxygen ALL 
	COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Generating Documentation with Doxygen"
	VERBATIM)
else(DOXYGEN_FOUND)
	message("Doxygen needs to be installed")
endif(DOXYGEN_FOUND)	

add_executable(my_project "")
add_subdirectory(src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
