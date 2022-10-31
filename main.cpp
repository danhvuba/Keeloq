

#include "header.h"

int main()
{
    uint64_t key = 0xB8952F5C78D06B3D; // 13300589148719049533;
    cout << "key: " << key << endl;
    Print_bit(key);

    uint32_t data = 0x78D06B3D; // 2026924861;
    cout << "\ndata:  " << data << endl;
    Print_bit(data);

    uint32_t cipher_text = Keeloq_Encrypt(data, key);
    cout << "\nciphertext:  " << cipher_text << "\n ";
    Print_bit(cipher_text);

    uint32_t plain_text = Keeloq_Descrypt(cipher_text, key);
    cout << "\nplaintext:  " << plain_text << endl;
    Print_bit(plain_text);

    ////////////////// r=4;
    // key >>> 4
    const int r = 4;
    uint64_t k0 = key;
    cout << "\n\n----";
    Print_bit(key);
    uint64_t kr = Rotation_key(k0, r);
    cout << "     key\n";
    Print_bit(kr);
    cout << "     key >>> 4\n";

    ////// search   ----||P>>4   =?   F_4(P,key) ---> i=8
    for (int i = 0; i < pow(2, 4); i++)
    {
        /// text------cipher (key)
        uint32_t P = data;
        cout << "\n  ____";
        Print_bit(data);
        cout << "     ____";
        Print_bit(cipher_text);
        cout << "\n  ";

        ////// ----||P>>4
        uint32_t P1 = (P >> r) ^ (i << (32 - r));
        Print_bit(P1);
        cout << "         ";
        uint32_t c_P = Keeloq_Encrypt(P1, kr);
        Print_bit(c_P);
        cout << "        i=" << i << "\n  ";
    }
}