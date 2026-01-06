add_library(maths STATIC
        matrix.cpp
)

target_include_directories(maths PUBLIC "${PROJECT_SOURCE_DIR}")
