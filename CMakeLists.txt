cmake_minimum_required (VERSION 2.6)
project (Data_Structure)

if(UNIX)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32 -g")
endif()

if(WIN32)
  foreach(var 
      CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
      CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
      CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
      CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
    )
    if(${var} MATCHES "/MDd")
      string(REGEX REPLACE "/MDd" "/MT" ${var} "${${var}}")
    endif()
  endforeach()
endif()

include_directories(include)

set(TEST_CASE dstest)
AUX_SOURCE_DIRECTORY(. SRC_MAIN)
AUX_SOURCE_DIRECTORY(sort SRC_SORT)
add_executable(${TEST_CASE} ${SRC_MAIN} ${SRC_SORT})
if (WIN32)
    target_link_libraries(${TEST_CASE} WS2_32)
endif()
