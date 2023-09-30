
    .type   _read_misa, @function
    .global _read_misa
_read_misa:
    csrr    a0, misa
    ret