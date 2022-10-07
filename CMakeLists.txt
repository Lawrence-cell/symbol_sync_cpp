#CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# Enable C++11
set(CMAKE_CXX_STANDARD 17)

# 项目信息
project (test_env)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量

# aux_source_directory(gr_symbolsycn DIR_SRCS)


# 指定生成目标 
# include_directories("/usr/local/include/gnuradio/")


include_directories(/home/yangguang/Desktop/gnuradio/gr-digital/lib)
include_directories(/home/yangguang/Desktop/gnuradio/gr-filter/include/)

macro(choose_file_to_compile filename)
    add_executable(test_env ${filename})
endmacro(choose_file_to_compile filename)

choose_file_to_compile(binay_read_test.cpp)


# find_library(boost)
list(INSERT CMAKE_MODULE_PATH 0 /home/yangguang/Desktop/gnuradio/cmake/Modules)
include(GrBoost)

target_link_libraries(test_env PUBLIC gnuradio-runtime gnuradio-filter gnuradio-blocks
gnuradio-analog Boost::boost volk gnuradio-digital fmt)


