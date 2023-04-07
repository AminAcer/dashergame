find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME}-launch main.cpp ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}-launch PRIVATE raylib)

#install(TARGETS ${PROJECT_NAME}-launch
#   EXPORT launchTarget
#         LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
#         ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
#         RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
#         INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/include
#       )


