//
// Project Name: rvxOS
// Filename: hex_digit.c
// Creator: Yaokai Liu
// Create Date: 2023-09-26
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

char hex_digit(unsigned int _i) {
    _i %= 16;
    if (_i < 10) {
        return '0' + _i;
    } else {
        return 'a' + _i - 10;
    }
}
