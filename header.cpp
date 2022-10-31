#include "header.h"

uint32_t Keeloq_Encrypt(uint32_t data, const uint64_t key)
{
    uint32_t x = data;
    for (int i = 0; i < 528; i++)
    {
        x = (x >> 1) ^ ((bit(Keeloq_NF, g5(x, 31, 26, 20, 9, 1)) ^ bit(x, 16) ^ bit(x, 0) ^ bit(key, i & 63)) << 31);
    }
    return x;
}

uint32_t Keeloq_Encrypt(uint32_t data, const uint64_t key, int r)
{
    uint32_t x = data;
    for (int i = 0; i < r; i++)
    {
        x = (x >> 1) ^ ((bit(Keeloq_NF, g5(x, 31, 26, 20, 9, 1)) ^ bit(x, 16) ^ bit(x, 0) ^ bit(key, i & 63)) << 31);
    }
    return x;
}

uint32_t Keeloq_Descrypt(uint32_t data, const uint64_t key)
{
    uint32_t x = data;
    for (int i = 0; i < 528; i++)
    {
        x = (x << 1) ^ (bit(Keeloq_NF, g5(x, 30, 25, 19, 8, 0)) ^ bit(x, 15) ^ bit(x, 31) ^ bit(key, (15 - i) & 63));
    }
    return x;
}

void Print_bit(uint32_t data)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << bit(data, i);
    }
}

void Print_bit(uint64_t key)
{
    for (int i = 63; i >= 0; i--)
    {
        cout << bit(key, i);
    }
}

uint64_t Rotation_key(uint64_t key, int r)
{
    uint64_t k = key;
    for (int i = 0; i < r; i++)
    {
        k = Rotation(k);
    }
    return k;
}