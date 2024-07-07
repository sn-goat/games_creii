# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/spell_boom_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/spell_boom_autogen.dir/ParseCache.txt"
  "spell_boom_autogen"
  )
endif()
