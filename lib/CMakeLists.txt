cmake_minimum_required(VERSION 2.8.7)

project(lib)

add_subdirectory(asio)
add_subdirectory(cluster)
add_subdirectory(elf-reader)
add_subdirectory(hook)
#add_subdirectory(host-harness)
#add_subdirectory(host-preload)
add_subdirectory(logger)
add_subdirectory(proc-reader)
add_subdirectory(test-case)
add_subdirectory(trace-analyzer)
add_subdirectory(llvm)
add_subdirectory(stp)

