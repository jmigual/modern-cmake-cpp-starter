set(TEST_NAME ${PROJECT_NAME}_test)

file(GLOB_RECURSE ${PROJECT_NAME}_TESTS CONFIGURE_DEPENDS "*.cpp")

add_executable(
  ${TEST_NAME}
  ${${PROJECT_NAME}_TESTS}
)

target_link_libraries(
  ${TEST_NAME}
  ${LIB_NAME}
  GTest::gtest_main
  GTest::gmock
)
target_compile_features(${TEST_NAME} PUBLIC cxx_std_20)
set_target_properties(
  ${TEST_NAME} PROPERTIES 
  CXX_EXTENSIONS OFF
)

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
