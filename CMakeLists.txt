cmake_minimum_required(VERSION 3.3)
project(boost_xp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost REQUIRED COMPONENTS log system thread filesystem signals)

message(status "** Boost Libraries: ${Boost_LIBRARIES}")

include_directories(/usr/local/include
                    01_RAII_Memory_Management
                    02_String_Handing
                    03_Containers
                    04_thread
                    .)

aux_source_directory(. SRC)
add_executable(boost_xp ${SRC})
target_link_libraries(boost_xp ${Boost_LIBRARIES})

