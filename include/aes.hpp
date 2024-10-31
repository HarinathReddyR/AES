#ifndef AES_H
#define AES_H

#include <iostream>
#include <array>
#include <cstdint>
#include <iomanip>
using namespace std;
class AES {
public:

    AES(const array<uint8_t, 16>& key) {
        keyExpansion(key);
        // for(int i=0;i<44;i++){
        //     cout<<"word"<<i<<' ';
        //     for(int j=0;j<4;j++){
        //         cout << hex << setfill('0') << setw(2) 
        //          << static_cast<int>(AES::words[i][j]) << ' ';
        //     }
        //     cout<<'\n';
        // }
    }
    void print(array<array<uint8_t, 4>, 4> state){
        cout<<"state:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                 cout << hex << setfill('0') << setw(2) 
                  << static_cast<int>(state[i][j]) << ' ';
            }
            cout<<'\n';
        }
    }


    array<uint8_t, 16> encrypt(const array<uint8_t, 16>& plaintext) {
        array<array<uint8_t, 4>, 4> state;
        for (int i = 0; i < 16; ++i) {
            state[i % 4][i / 4] = plaintext[i]; 
        }
        // print(state);
        addRoundKey(state, 0); 
        // print(state);
        for (int round = 1; round <= 9; ++round) {
            subBytes(state);
            shiftRows(state);
            mixColumns(state);
            addRoundKey(state, round*4);
        }
        
        subBytes(state);
        shiftRows(state);
        addRoundKey(state, 40); 
        
        array<uint8_t, 16> output;
        for (int i = 0; i < 16; ++i) {
            output[i] = state[i % 4][i / 4]; 
        }
        
        return output;
    }

    array<uint8_t, 16> decrypt(const array<uint8_t, 16>& ciphertext) {
        array<array<uint8_t, 4>, 4> state;
        for (int i = 0; i < 16; ++i) {
            state[i % 4][i / 4] = ciphertext[i]; 
        }
        // print(state);
        addRoundKey(state, 40); 
        
        for (int round = 9; round >= 1; --round) {
            inverseShiftRows(state);
            inverseSubBytes(state);
            addRoundKey(state, round*4);
            // print(state);
            inverseMixColumns(state);
        }
        
        inverseShiftRows(state);
        inverseSubBytes(state);
        addRoundKey(state,0); 
        
        array<uint8_t, 16> output;
        for (int i = 0; i < 16; ++i) {
            output[i] = state[i % 4][i / 4]; 
        }
        
        return output;
    }

private:

    array<array<uint8_t,4>,44> words;
    static const array<uint8_t,10> rc;
    static const uint8_t sbox[16][16];
    static const uint8_t inv_sbox[16][16];

    // AES transformation functions
    void subBytes(array<array<uint8_t, 4>, 4>& state);
    void shiftRows(array<array<uint8_t, 4>, 4>& state);
    void mixColumns(array<array<uint8_t, 4>, 4>& state);
    void addRoundKey(array<array<uint8_t, 4>, 4>& state, int r);
    
    // Inverse transformation functions
    void inverseSubBytes(array<array<uint8_t, 4>, 4>& state);
    void inverseShiftRows(array<array<uint8_t, 4>, 4>& state);
    void inverseMixColumns(array<array<uint8_t, 4>, 4>& state);
    
    // Key schedule function
    void keyExpansion(const array<uint8_t, 16>& key);
    array<uint8_t,4> subWord(array<uint8_t,4> word);
    array<uint8_t,4> rotWord(array<uint8_t,4> word);
    array<uint8_t,4> xorRC(array<uint8_t,4> word,int rcon);
    array<uint8_t,4> xorWord(array<uint8_t,4> word,array<uint8_t,4> prev);
    
    uint8_t gf_mult(uint8_t a, uint8_t b);
};

#endif 
