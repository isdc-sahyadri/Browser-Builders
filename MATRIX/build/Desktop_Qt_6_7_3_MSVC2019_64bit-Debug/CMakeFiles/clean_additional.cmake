# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MATRIX_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MATRIX_autogen.dir\\ParseCache.txt"
  "MATRIX_autogen"
  )
endif()
