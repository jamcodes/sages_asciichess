cmake_minimum_required(VERSION 3.13)
project(asciichess CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME}
    main.cpp
    chessboard.cpp
    piece.cpp
    console_visitor.cpp

    chessboard.hpp
    piece.hpp
    settings.hpp
    console_visitor.hpp
)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_features(${PROJECT_NAME}
    PUBLIC
        cxx_std_17
)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Wextra
        -pedantic
        -Weffc++
        -Wshadow
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Wcast-align
        -Wunused
        -Woverloaded-virtual
        -Wpedantic
        -Wconversion
        -Wsign-conversion
        -Wnull-dereference
        -Wdouble-promotion
        -Wformat=2
        -Wmisleading-indentation
        -Wduplicated-cond
        -Wduplicated-branches
        -Wlogical-op
        -Wuseless-cast
        $<$<CONFIG:Debug>:-ggdb3>
)
target_compile_options(${PROJECT_NAME}
    PUBLIC
        -fuse-ld=gold
)
# add_library(board OBJECT
#     board.cpp
#     board.hpp
# )
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        # board
        -lstdc++fs
)
