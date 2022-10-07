/*
 * @Author: yanggguang 850140027@qq.com
 * @Generate Date: Do not edit
 * @LastEditors: Lawrence_cell 850140027@qq.com
 * @LastEditTime: 2022-10-06 07:07:25
 * @FilePath: /SymbolSync/symbol_sync_test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Lawrence_cell 850140027@qq.com, All Rights Reserved.
 */
#pragma once
#include "timing_error_detector.cc"
#include "interpolating_resampler.cc"
#include "clock_tracking_loop.cc"
#include <gnuradio/digital/timing_error_detector_type.h>
#include <fstream>
#include <iostream>
using namespace gr::digital;

int main()
{
    auto d_ted = timing_error_detector::make(TED_GARDNER);
    auto d_interp = interpolating_resampler_fff::make(ir_type::IR_MMSE_8TAP);
    auto d_clock = clock_tracking_loop(0.045, 8 + 1.5, 8 - 1.5, 8, 1, 1);

    gr_complex s;

    int len_char = 0;

    std::ifstream inFile("../symbol_sync_py/data_grc/befor_sysmbol_sync", std::ios::in | std::ios::binary); //二进制读方式打开
    if (!inFile)
    {
        std::cout << "error" << std::endl;
        return 0;
    }
    while (inFile.read(&s, sizeof(s)))
    {
        int readedBytes = inFile.gcount();
        std::cout << s << std::endl;
    }

    inFile.close();

    // std::cout << sizeof(char *) << std::endl;
}
