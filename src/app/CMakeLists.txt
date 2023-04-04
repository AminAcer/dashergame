cmake_minimum_required(VERSION 3.25)
project(dasher)

add_executable(launch main.cpp)
target_link_libraries(launch PRIVATE raylib)
install(TARGETS launch
         EXPORT launchTargets
         LIBRARY DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lib
         ARCHIVE DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lib
         RUNTIME DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin
         INCLUDES DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include
       )


