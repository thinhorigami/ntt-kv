
include (config.cmake)
include (ntt-kv.cmake)

if (ntt_project_on_top())
  message(STATUS "${NTT_KV} is on top")
  message(STATUS "${NTT_KV} source path: ${PROJECT_SOURCE_DIR}/${NTT_KV_SRC_PREFIX}")
  message(STATUS "${NTT_KV} include path: ${PROJECT_SOURCE_DIR}/${NTT_KV_INCLUDE_PREFX}")
else()
  message(FATAL_ERROR "${NTT_KV} not on top")
endif()