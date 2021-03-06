# ================================================================================
# CashewMath
# ================================================================================
project(CashewMath LANGUAGES CXX
		  DESCRIPTION "A lightweight, header only math library."
		  HOMEPAGE_URL "https://github.com/Kejoko/CashewMath")

cmake_minimum_required(VERSION 3.11)

# ================================================================================
# CMake modules
# ================================================================================
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(create_unit_test)

# ================================================================================
# C++ 11 support
# ================================================================================
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ================================================================================
# Create interface library
# ================================================================================
set(cm_master_header
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Cashew/Math.h)

set(linear_headers
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Cashew/Linear.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Cashew/Linear/Matrix.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Cashew/Linear/Vector.h)

add_library(CashewMath INTERFACE)
target_sources(CashewMath INTERFACE "$<BUILD_INTERFACE:${cm_master_header};${linear_headers}>")
target_include_directories(CashewMath INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

# ================================================================================
# Testing
# ================================================================================
enable_testing()

add_subdirectory(test/)