
set(APP_NAME "app")

set(${APP_NAME}_INCLUDE_DIR "include")

# This is discouraged as some generators do not support the "CONFIGURE_DEPENDS" option.
# The alternative is to list all the files manually in add_library
file(GLOB_RECURSE ${APP_NAME}_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE ${APP_NAME}_HEADERS CONFIGURE_DEPENDS "include/*.hpp")

add_executable(${APP_NAME} ${${APP_NAME}_SOURCES} ${${APP_NAME}_HEADERS})

target_include_directories(${APP_NAME} PUBLIC ${${APP_NAME}_INCLUDE_DIR})

target_link_libraries(${APP_NAME} PRIVATE ${LIB_NAME} fmt::fmt nlohmann_json::nlohmann_json benchmark::benchmark)
target_compile_features(${APP_NAME} PUBLIC cxx_std_23)
set_target_properties(${APP_NAME} PROPERTIES CXX_EXTENSIONS OFF)

