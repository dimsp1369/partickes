cmake_minimum_required(VERSION 3.28)
project(particles)

set(CMAKE_CXX_STANDARD 17)

add_executable(particles code/main.cpp
        code/Engine.cpp
        code/Particle.cpp
        code/Matrices.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories("C:/SFML/include")
target_link_libraries(particles sfml-graphics sfml-window sfml-system sfml-audio sfml-network)


