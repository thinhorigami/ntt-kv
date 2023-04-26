
if(${NTT_TEST})
  include(CTest)

  enable_testing()

  add_executable(${NTT_KV_TEST} src/test.cpp)

  target_compile_features(${NTT_KV_TEST} PRIVATE cxx_std_23)

  target_include_directories(${NTT_KV_TEST}
    PRIVATE
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include>
  )

  target_link_libraries(${NTT_KV_TEST} PRIVATE ntt::kv)

  find_package(Catch2 CONFIG REQUIRED)
  target_link_libraries(${NTT_KV_TEST} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)

  add_test(NAME $(NTT_KV_TEST) COMMAND ${NTT_KV_TEST})

  add_custom_command(TARGET ${NTT_KV_TEST} POST_BUILD
    COMMAND ctest --output-in-failure
    WORKING_DIRECTORY $<TARGET_FILE_DIR:${NTT_KV_TEST}>
    COMMAND_EXPAND_LISTS
  )

endif()