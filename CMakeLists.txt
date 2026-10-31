cmake_minimum_required(VERSION 3.14)
project(flatrate-math VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(flatrate-math src/math.cpp)
target_include_directories(flatrate-math
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

add_executable(math_test tests/math_test.cpp)
target_link_libraries(math_test PRIVATE flatrate-math)
enable_testing()
add_test(NAME math_test COMMAND math_test)

include(GNUInstallDirs)
install(TARGETS flatrate-math
        EXPORT flatrate-math-targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT flatrate-math-targets
        NAMESPACE flatrate::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/flatrate-math)
