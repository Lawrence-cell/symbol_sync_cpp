/*
 * @Author: yanggguang 850140027@qq.com
 * @Generate Date: Do not edit
 * @LastEditors: Lawrence_cell 850140027@qq.com
 * @LastEditTime: 2022-10-06 05:43:08
 * @FilePath: /SymbolSync/ted_test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Lawrence_cell 850140027@qq.com, All Rights Reserved.
 */
#include "timing_error_detector.h"
#include <iostream>
#include <complex>
#include <complex.h>

using namespace gr::digital;

int main()
{
    auto d_ted = timing_error_detector::make(TED_GARDNER);

    // d_ted.input(complex(1 + 2j))
    // d_ted.input(complex(1 + 3j))
    // d_ted.input(complex(2 + 3j))

    d_ted->input(1 + 2I);
    d_ted->input(1 + 3I);
    d_ted->input(2 + 3I);
    // 2 * (1 - 3)
    std::cout << d_ted->error() << std::endl;

    return 0;
}
