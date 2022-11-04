

#include "header.h"

int main()
{
    uint64_t key =0xB3952B5CA8D06B3D ;//0xB8952F5C78D06B3D; // 13300589148719049533;
    cout << "key: " << key << endl;
    Print_bit(key);

    uint32_t data = 0x7AEB6B3D; // 2026924861;
    cout << "\ndata:  " << data << endl;
    Print_bit(data);

    uint32_t cipher_text = Keeloq_Encrypt(data, key);
    cout << "\nciphertext:  " << cipher_text << "\n ";
    Print_bit(cipher_text);

    // uint32_t plain_text = Keeloq_Descrypt(cipher_text, key);
    // cout << "\nplaintext:  " << plain_text << endl;
    // Print_bit(plain_text);
    cout << endl;

    for (int i = 15; i < 18; i++)
    {
        Find_P(data, key, i);
    }
    cout << endl;
}