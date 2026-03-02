cmake_minimum_required(VERSION 3.23)

find_package(benchmark REQUIRED CONFIG)

add_executable(GreeterBenchmark benchmark.cpp)

target_link_libraries(GreeterBenchmark 
    PRIVATE GreeterLib
    PRIVATE benchmark::benchmark
)

add_executable(ContainerFindComplexityBenchmark container_benchmark.cpp)

target_link_libraries(ContainerFindComplexityBenchmark 
    PRIVATE benchmark::benchmark
)

add_executable(ThreadsBenchmark threads_benchmark.cpp)

target_link_libraries(ThreadsBenchmark 
    PRIVATE benchmark::benchmark
)
