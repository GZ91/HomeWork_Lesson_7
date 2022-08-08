# CMakeList.txt: проект CMake для MyCMAKE_TEST; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)


# Добавьте источник в исполняемый файл этого проекта.
add_executable (MyCMAKE_TEST "main.cpp" "list_container.hpp" "serial_container.hpp" "singly_linked_list_container.hpp" "util.hpp")

# Add src to the include directories for the test target
target_include_directories(
    MyCMAKE_TEST PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
# Add googletest to the include directories for the test target
target_include_directories(
    MyCMAKE_TEST PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

# Link test target against gtest libraries
target_link_libraries(
    MyCMAKE_TEST PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)

if (MSVC)
    target_compile_options(
        MyCMAKE_TEST PRIVATE
        /W4
    )
else ()
    target_compile_options(
        MyCMAKE_TEST PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
