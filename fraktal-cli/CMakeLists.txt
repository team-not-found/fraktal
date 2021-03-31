
file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.hpp)

add_executable(fraktal-cli ${SRCS} ${HDRS})

target_link_libraries(fraktal-cli 
                        PRIVATE fraktal
                        )

install(TARGETS fraktal-cli DESTINATION bin)