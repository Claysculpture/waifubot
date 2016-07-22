include_directories(${WaifuBot_SOURCE_DIR}/headers)
FILE(GLOB AllSources *.cpp)
add_executable(WaifuBot ${AllSources})
