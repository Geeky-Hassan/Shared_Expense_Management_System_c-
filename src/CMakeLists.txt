set(IS_GNU "$<CXX_COMPILER_ID:GNU>")
set(IS_MSVC "$<CXX_COMPILER_ID:MSVC>")

add_executable(tests test_expense_balancer.cpp expense_balancer.cpp)

target_compile_features(tests
  PRIVATE
    cxx_std_17
)

target_compile_options(tests
  PRIVATE
    "$<${IS_GNU}:-Wall;-Wextra;-Wshadow;-pedantic>"
    "$<${IS_MSVC}:/permissive-;/W4>"
)

target_include_directories(tests
  PRIVATE
    "${PROJECT_SOURCE_DIR}/lib/"
)
