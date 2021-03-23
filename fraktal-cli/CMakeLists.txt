
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

add_executable(fraktal-cli ${SRCS} ${HDRS})

target_link_libraries(fraktal-cli 
                        PRIVATE static-fraktal
                        )