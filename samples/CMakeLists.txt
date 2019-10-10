message(STATUS "Generating samples")

add_executable(rag.example src/example.cpp)
target_link_libraries(rag.example rag)

message(STATUS "Generating samples - done")
