find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME}-launch main.cpp)
target_link_libraries(${PROJECT_NAME}-launch PRIVATE raylib ${PROJECT_NAME}-lib)

