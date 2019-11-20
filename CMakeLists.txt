cmake_minimum_required(VERSION 2.8)

SET(LIBRARY_NAME "ReferencedCountedPointer")
SET(EXECUTABLE_NAME "Starup")
PROJECT(${LIBRARY_NAME})

# CACHE variables are stored in the cache file and persited over cmake runs
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "Configs" FORCE)
 
IF(DEFINED CMAKE_BUILD_TYPE)
	SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})
ENDIF()



SET(LIB_SOURCES 
	src/RefCounter.cpp)

add_library(${LIBRARY_NAME} SHARED ${LIB_SOURCES})
set_target_properties(${LIBRARY_NAME} PROPERTIES PUBLIC_HEADER include/RefCountedPointer.h)



add_executable(${EXECUTABLE_NAME} main.cpp)


target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME})

install(TARGETS ${LIBRARY_NAME} ${EXECUTABLE_NAME}
		LIBRARY       DESTINATION bin
		PUBLIC_HEADER DESTINATION include
		RUNTIME      DESTINATION bin)


	
 