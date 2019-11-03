cmake_minimum_required(VERSION 2.8)

SET(PROJECT_NAME "ReferencedCountedPointer")
PROJECT(${PROJECT_NAME})

# CACHE variables are stored in the cache file and persited over cmake runs
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "Configs" FORCE)
 
IF(DEFINED CMAKE_BUILD_TYPE)
	SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})
ENDIF()

include_directories(${PROJECT_SOURCE_DIR}/include)


add_library(lib src/RefCounter.cpp)

add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME} lib)


	
 