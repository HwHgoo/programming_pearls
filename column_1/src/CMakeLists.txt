include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# aux_source_directory(. LIB_SRCS)
file(GLOB LIB_SRCS *.c)
add_library(myhead ${LIB_SRCS})
