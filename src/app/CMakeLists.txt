find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME}-launch main.cpp ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}-launch PRIVATE raylib)

#install(TARGETS launch
#   EXPORT launchTarget
#         LIBRARY DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lib
#         ARCHIVE DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/lib
#         RUNTIME DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin
#         INCLUDES DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include
#       )


