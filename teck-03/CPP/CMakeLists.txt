cmake_minimum_required(VERSION 3.17)
project (RType)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS NO_OUTPUT_DIRS)

file(GLOB SRC_SERVER "src/server/*.cpp")
file(GLOB SRC_CLIENT "src/client/*.cpp")
file(GLOB SRC_ECS "src/*.cpp")

include_directories (./include)

add_executable (r-type_server ${SRC_SERVER})
add_executable (r-type_client ${SRC_CLIENT})
##add_executable (ecs ${SRC_ECS})

conan_target_link_libraries(r-type_server ${CONAN_LIBS})
conan_target_link_libraries(r-type_client ${CONAN_LIBS})
##conan_target_link_libraries(ecs ${CONAN_LIBS})
