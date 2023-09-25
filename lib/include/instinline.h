//
// Created by Yaokai Liu on 2023/5/12.
//

#ifndef _INSTINLINE_H_
#define _INSTINLINE_H_

#include <xtypes.h>
typedef xLong   reg_int;

reg_int inst_add(reg_int _rs1, reg_int _rs2) __attribute__((always_inline));

#endif //_INSTINLINE_H_
