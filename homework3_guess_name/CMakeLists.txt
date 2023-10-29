cmake_minimum_required(VERSION 3.12)

project(03.homework)

add_subdirectory(random_value)

add_executable(
        guess_the_number
        guess_the_number.cpp
        random_value/random_value.cpp
        check_value.cpp
        print_table_score.cpp
        random_value/random_value.h
        check_value.h
        print_table_score.h
)

set_target_properties(guess_the_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
