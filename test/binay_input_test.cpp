/*
 * @Author: yanggguang 850140027@qq.com
 * @Generate Date: Do not edit
 * @LastEditors: Lawrence_cell 850140027@qq.com
 * @LastEditTime: 2022-10-06 07:17:33
 * @FilePath: /SymbolSync/binay_input_test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Lawrence_cell 850140027@qq.com, All Rights Reserved.
 */
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i] = i;
    }
    ofstream outFile("/home/yangguang/Desktop/test", ios::out | ios::binary);

    outFile.write((char *)&a, sizeof(int));
    outFile.close();
    return 0;
}
