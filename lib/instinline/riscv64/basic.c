//
// Created by Yaokai Liu on 2023/5/12.
//

#include <instinline.h>

reg_int inst_add(reg_int _rs1, reg_int _rs2) {
    reg_int rd;
    __asm__ __volatile__ ("add   %2, %0, %1\n" :"r"(_rs1) :"r"(_rs2) :"=r"(rd));
    return rd;
}

