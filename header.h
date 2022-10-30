#include <iostream>

using namespace std;

#define Keeloq_NF 0x3A5C742E
#define bit(x, n) ((x >> n) & 1)
#define g5(x, a, b, c, d, e) (bit(x, a) * 16 + bit(x, b) * 8 + bit(x, c) * 4 + bit(x, d) * 2 + bit(x, e))

uint32_t Keeloq_Encrypt(uint32_t x, const uint64_t key);
uint32_t Keeloq_Descrypt(uint32_t x, const uint64_t key);
void Print_bit(uint32_t data);
void Print_bit(uint64_t key);