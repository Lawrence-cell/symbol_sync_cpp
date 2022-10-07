/*
 * @Author: yanggguang 850140027@qq.com
 * @Generate Date: Do not edit
 * @LastEditors: Lawrence_cell 850140027@qq.com
 * @LastEditTime: 2022-10-06 19:53:42
 * @FilePath: /SymbolSync/binay_read_test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Lawrence_cell 850140027@qq.com, All Rights Reserved.
 */
// This is C++17
#include <algorithm>
#include <cmath>
#include <complex>
#include <cstddef>
#include <filesystem>
#include <fstream>
#include <string_view>
#include <vector>
#include <iostream>

#include <fmt/format.h>
#include <fmt/ranges.h>

using sample_t = std::complex<float>;
using power_t = float;
constexpr std::size_t read_block_size = 1 << 16;

int main()
{
    // expect exactly one argument, a file name

    // just for convenience; we could as well just use `argv[1]` throughout the
    // code

    std::string_view filename("/home/yangguang/Desktop/symbol_sync_py/data_grc/befor_sysmbol_sync");

    // check whether file exists
    if (!std::filesystem::exists(filename.data()))
    {
        fmt::print(stderr, "file '{:s}' not found\n", filename);
        return -2;
    }

    // calculate how many samples to read
    auto file_size = std::filesystem::file_size(std::filesystem::path(filename));
    auto samples_to_read = file_size / sizeof(sample_t);

    // construct and reserve container for resulting powers
    std::vector<power_t> powers;
    powers.reserve(samples_to_read);

    std::ifstream input_file(filename.data(), std::ios_base::binary);
    if (!input_file)
    {
        fmt::print(stderr, "error opening '{:s}'\n", filename);
        return -3;
    }

    // construct and reserve container for read samples
    // if read_block_size == 0, then read the whole file at once
    std::vector<sample_t> samples;
    if (read_block_size)
        samples.resize(read_block_size);
    else
        samples.resize(samples_to_read);

    fmt::print(stderr, "Reading {:d} samples…\n", samples_to_read);
    while (samples_to_read)
    {
        auto read_now = std::min(samples_to_read, samples.size());
        input_file.read(reinterpret_cast<char *>(samples.data()),
                        read_now * sizeof(sample_t));
        for (size_t idx = 0; idx < read_now; ++idx)
        {
            auto magnitude = std::abs(samples[idx]);
            powers.push_back(magnitude * magnitude);
        }
        samples_to_read -= read_now;
    }
    for (int i = 0; i < 100; i++)
    {
        std::cout << samples[i] << std::endl;
    }

    // we're not actually doing anything with the data. Let's print it!
    fmt::print("Power\n{}\n", fmt::join(powers, "\n"));
}