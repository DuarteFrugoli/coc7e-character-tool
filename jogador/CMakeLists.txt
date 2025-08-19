set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB JOGADOR_SOURCES src/*.cpp)

add_executable(jogador ${JOGADOR_SOURCES})