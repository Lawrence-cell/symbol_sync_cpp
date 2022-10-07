/*
 * @Author: yanggguang 850140027@qq.com
 * @Generate Date: Do not edit
 * @LastEditors: Lawrence_cell 850140027@qq.com
 * @LastEditTime: 2022-10-05 20:33:09
 * @FilePath: /SymbolSync/clock_loop_test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Lawrence_cell 850140027@qq.com, All Rights Reserved.
 */
#include "clock_tracking_loop.cc"
#include <iostream>

using namespace gr::digital;

int main()
{
    auto d_clock = clock_tracking_loop(0.045, 8 + 1.5, 8 - 1.5, 8, 1, 1);

    d_clock.advance_loop(2);
    std::cout << d_clock.get_avg_period() << std::endl;
}
