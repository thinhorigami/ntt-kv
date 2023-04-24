
if(${NTT_BUILD_TEST})
  include(CTest)

  enable_testing()

  add_executable(${NTT_KV_TEST} src/test.cpp)

  find_package(Catch2 CONFIG REQUIRED)
  target_link_libraries(${NTT_KV_TEST} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)

  add_test(NAME $(NTT_KV_TEST) COMMAND ${NTT_KV_TEST})

  add_custom_command(${NTT_KV_TEST} POST_BUILD
    COMMAND ctest -C $<CONFIGURATION>
  )

endif()