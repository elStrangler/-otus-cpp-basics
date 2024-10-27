cmake_minimum_required(VERSION 3.5)

project(03.homework)

add_executable(gues_the_number
	gues_the_number.cpp
)

set_target_properties(gues_the_number PROPERTIES
	CXX_STANDART 17
	CXX_STANDART_REQUIRED ON
	)