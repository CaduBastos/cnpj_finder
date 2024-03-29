# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CNPJ_Formatter_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CNPJ_Formatter_autogen.dir/ParseCache.txt"
  "CNPJ_Formatter_autogen"
  )
endif()
