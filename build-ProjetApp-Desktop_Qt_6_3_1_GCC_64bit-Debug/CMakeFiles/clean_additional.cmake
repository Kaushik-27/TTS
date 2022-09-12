# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ProjetApp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ProjetApp_autogen.dir/ParseCache.txt"
  "ProjetApp_autogen"
  )
endif()
