file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.hpp)

add_library(static-fraktal STATIC
    ${SRCS}
    ${HDRS}
)

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