cmake_minimum_required(VERSION 3.26)
project(TOSN)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/core)
include_directories(src/tsp)

add_executable(TOSN
        src/core/algorithms.cpp
        src/core/algorithms.h
        src/core/deployment.cpp
        src/core/deployment.h
        src/core/sensor.cpp
        src/core/sensor.h
        src/input.cpp
        src/input.h
        src/main.cpp
        src/tsp/tsp.h
        src/tsp/tsp.cpp
        src/model/energy.cpp
        src/model/energy.h
        src/model/quartic.cpp
        src/definitions.h
        src/output.cpp
        src/output.h)
