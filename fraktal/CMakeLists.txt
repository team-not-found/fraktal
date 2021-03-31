file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.hpp)

add_library(static-fraktal STATIC
    ${SRCS}
    ${HDRS}
)

set_target_properties(static-fraktal PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

add_library(fraktal SHARED
    ${SRCS}
    ${HDRS}
)

add_executable(test test/main.cpp ${SRCS} ${HDRS})

target_include_directories(static-fraktal
                         PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
                         )

target_include_directories(fraktal
                         PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
                         )

install(TARGETS fraktal DESTINATION lib)
install(DIRECTORY src/ DESTINATION include/fraktal
        FILES_MATCHING PATTERN "*.hpp")