include_directories(${WaifuBot_SOURCE_DIR}/headers)
include_directories($ENV{BOOST_INCL})
link_directories($ENV{BOOST_STAGE}/lib)
FILE(GLOB_RECURSE AllHeaders ${WaifuBot_SOURCE_DIR}/headers/*.h)
FILE(GLOB AllSources *.cpp)
source_group("Headers" FILES ${AllHeaders})
set(SOURCES ${AllSources} ${AllHeaders})
add_executable(WaifuBot ${SOURCES})
if(WIN32)
	#NOTE: Build will fail if the project is not reconfigured to use a static runtime library
	#TODO: Do something to fix this
	target_link_libraries(WaifuBot libboost_thread-vc140-mt-s-1_61.lib libboost_system-vc140-mt-s-1_61.lib)
else()
	message(FATAL_ERROR "non-windows operating systems are not currently supported")
	#TODO: Prepare link for non-windows systems
endif()
