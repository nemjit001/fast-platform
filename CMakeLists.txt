cmake_minimum_required(VERSION 3.14)
project("Fast Platform Layer" VERSION 0.1.0)

file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS "include/*.hpp")

add_library(fpl INTERFACE
	${PROJECT_HEADERS}
)
target_include_directories(fpl INTERFACE "include/")
