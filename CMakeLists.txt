cmake_minimum_required(VERSION 3.26)

project(ntt-kv
  LANGUAGES CXX
)

include(cmake/ntt-kv.cmake)

add_library(${NTT_KV})

target_compile_features(${NTT_KV} PRIVATE cxx_std_23)

target_sources(${NTT_KV}
  PRIVATE
  ${NTT_KV_SRC_PREFIX}/kv.cpp
)

target_include_directories(${NTT_KV}
  PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# dependencies
find_package(inja CONFIG REQUIRED)
target_link_libraries(${NTT_KV} PRIVATE pantor::inja)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(${NTT_KV} PRIVATE benchmark::benchmark benchmark::benchmark_main)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${NTT_KV} PRIVATE fmt::fmt)

# this is heuristically generated, and may not be correct
find_package(inja CONFIG REQUIRED)
target_link_libraries(${NTT_KV} PRIVATE pantor::inja)

# this is heuristically generated, and may not be correct
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${NTT_KV} PRIVATE spdlog::spdlog spdlog::spdlog_header_only)

add_subdirectory(test)