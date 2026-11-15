cmake_minimum_required(VERSION 3.15)
project(HH3Smoke LANGUAGES C ASM)

include(GenerateHH3)
find_package(Gint 2.11 REQUIRED)

add_executable(hh3-smoke main.c)
target_link_libraries(hh3-smoke Gint::Gint)
generate_hh3(TARGET hh3-smoke OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/gint-smoke.hh3")
