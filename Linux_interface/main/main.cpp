/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  7/11 11:26:03 2022
 ************************************************************************/

#include<iostream>
#include "time/timeutil.h"


int main() {
    uint64_t start = timeNow();
    int i = 100000;
    while(i--);
    uint64_t end = timeNow();
    std::cout << "timeout: " << std::endl; 
    std::cout << end - start << std::endl;
    return 0;

}
