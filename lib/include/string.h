//
// Created by Yaokai Liu on 2023/5/12.
//

#ifndef _STRING_H_
#define _STRING_H_  1

#include <xtypes.h>
#include <xdef.h>

#ifdef __cplusplus
extern "C" {
#endif

    xInt memcmp(const xVoid * _m_ptr1, const xVoid * _m_ptr2, xSize _size);
    xVoid* memcpy(xVoid * __restrict _dest, const xVoid * __restrict _target, xSize _size);
    xVoid* memset(xVoid* _m_ptr, xuByte _val, xSize _size);
    xSize strlen(const xuByte * _str);

#ifdef __cplusplus
};
#endif

#endif //_STRING_H_
