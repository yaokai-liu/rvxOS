//
// Project Name: rvxOS
// Filename: upper_c.c
// Creator: Yaokai Liu
// Create Date: 2023-09-26
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

char upper_c(char _c) {
    return ('a' <= _c && _c <= 'z') ? (_c + 'A' - 'a') : _c;
}
