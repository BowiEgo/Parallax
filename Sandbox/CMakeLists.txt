project(Sandbox VERSION 1.0.0)

file(GLOB_RECURSE sandbox_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
file(GLOB_RECURSE sandbox_headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)
add_executable(${PROJECT_NAME} ${sandbox_sources} ${sandbox_headers})
set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})

target_include_directories(${PROJECT_NAME} PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
  "${CMAKE_SOURCE_DIR}/ChozoEngine/src"
)

target_link_libraries(${PROJECT_NAME} PUBLIC ChozoEngine)
