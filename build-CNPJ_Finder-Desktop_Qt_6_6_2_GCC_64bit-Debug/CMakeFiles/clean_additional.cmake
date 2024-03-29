# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CNPJ_Finder_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CNPJ_Finder_autogen.dir/ParseCache.txt"
  "CNPJ_Finder_autogen"
  )
endif()
