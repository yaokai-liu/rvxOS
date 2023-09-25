//
// Created by Yaokai Liu on 2023/5/12.
//

#include <string.h>

xInt memcmp(const xVoid * _m_ptr1, const xVoid * _m_ptr2, xSize _size) {
    const xuByte * _b_ptr1 = _m_ptr1, * _b_ptr2 = _m_ptr2;
    while (_size && *_b_ptr1 == *_b_ptr2) _size--, _b_ptr1++, _b_ptr2++;
    return _size ? *_b_ptr1 - *_b_ptr2 : 0;
}
