# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("MyCMAKE_TEST")

find_package(GTest)

# Включите подпроекты.
add_subdirectory ("MyCMAKE_TEST")
