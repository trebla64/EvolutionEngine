cmake_minimum_required(VERSION 3.9)

set (PROJECT EvolutionEngine)

# add source files
file(GLOB_RECURSE EE_SOURCES "src/EvolutionEngine/*.cpp")
file(GLOB_RECURSE EE_HEADERS "src/EvolutionEngine/*.h" "src/EvolutionEngine/*.hpp")