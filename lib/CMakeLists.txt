
set(LIB_NAME "greeter")

# Export the library name to the parent scope
set(LIB_NAME ${LIB_NAME} PARENT_SCOPE)

set(${LIB_NAME}_INCLUDE_DIR "include")
set(${LIB_NAME}_INCLUDE_DIR_PRIVATE "include/${LIB_NAME}")

# This is discouraged as some generators do not support the "CONFIGURE_DEPENDS" option.
# The alternative is to list all the files manually in add_library
file(GLOB_RECURSE ${LIB_NAME}_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE ${LIB_NAME}_HEADERS CONFIGURE_DEPENDS "include/*.hpp")

add_library(${LIB_NAME} ${${LIB_NAME}_SOURCES} ${${LIB_NAME}_HEADERS})

target_include_directories(${LIB_NAME} 
  PUBLIC ${${LIB_NAME}_INCLUDE_DIR} 
  PRIVATE ${${LIB_NAME}_INCLUDE_DIR_PRIVATE}
)

target_compile_features(${LIB_NAME} PUBLIC cxx_std_20)
target_link_libraries(${LIB_NAME} PRIVATE fmt::fmt)
set_target_properties(${LIB_NAME} PROPERTIES CXX_EXTENSIONS OFF)
