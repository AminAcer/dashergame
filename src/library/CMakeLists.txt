target_compile_features(${PROJECT_NAME}-launch PRIVATE cxx_std_20)

set(INCLUDE_DIRS
   ${CMAKE_SOURCE_DIR}/include/
)

set(SOURCE_FILES
   ${CMAKE_SOURCE_DIR}/src/library/Texture.cpp
)

target_include_directories(${PROJECT_NAME}-launch PRIVATE ${INCLUDE_DIRS})

#target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
