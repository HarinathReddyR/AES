#include <iostream>
#include <array>
#include "../include/aes.hpp"
using namespace std;
int main() {
    array<uint8_t, 16> key = {0x0f, 0x15, 0x71, 0xc9, 
                                0x47, 0xd9, 0xe8, 0x59, 
                                0x0c, 0xb7, 0xad, 0xd6, 
                                0xaf, 0x7f, 0x67, 0x98};
    array<uint8_t, 16> plaintext = {0x01, 0x23, 0x45, 0x67, 
                                      0x89, 0xab, 0xcd, 0xef, 
                                      0xfe, 0xdc, 0xba, 0x98, 
                                      0x76, 0x54, 0x32, 0x10};
    AES aes(key);
    cout << "plaintext: ";
    for (const auto& byte : plaintext) {
        cout << hex << setfill('0') << setw(2) 
                  << static_cast<int>(byte) << ' ';
    }
    cout<<'\n';
    cout << "key: ";
    for (const auto& byte : key) {
        cout << hex << setfill('0') << setw(2) 
                  << static_cast<int>(byte) << ' ';
    }
    cout<<'\n';
    // Encrypt
    auto ciphertext = aes.encrypt(plaintext);
    
    cout << "Ciphertext: ";
    for (const auto& byte : ciphertext) {
        cout << hex << setfill('0') << setw(2) << static_cast<int>(byte) << ' ';
    }
    cout<<'\n';

    // Decrypt 
    auto decrypted = aes.decrypt(ciphertext);
    cout << "Decrypted: ";
    for (const auto& byte : decrypted) {
        cout << hex << setfill('0') << setw(2) << static_cast<int>(byte) << ' ';
    }
    cout<<'\n';

    return 0;
}
