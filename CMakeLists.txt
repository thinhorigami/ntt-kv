cmake_minimum_required(VERSION 3.26)

project(ntt-kv
  LANGUAGES CXX
)

include(cmake/ntt-kv.cmake)

add_library(${NTT_KV})
add_library(ntt::kv ALIAS ${NTT_KV})

target_compile_features(${NTT_KV} PRIVATE cxx_std_23)

target_sources(${NTT_KV}
  PRIVATE
    ${NTT_KV_SRC_PREFIX}/kv.cpp
)

target_include_directories(${NTT_KV}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# dependencies
find_package(inja CONFIG REQUIRED)
target_link_libraries(${NTT_KV} PRIVATE pantor::inja)

find_package(benchmark CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(inja CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

target_link_libraries(${NTT_KV}
  PRIVATE
    benchmark::benchmark
    benchmark::benchmark_main
    fmt::fmt
    pantor::inja
    spdlog::spdlog
    spdlog::spdlog_header_only
)

install(TARGETS ${NTT_KV}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

add_subdirectory(test)