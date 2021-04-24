/**
 * @file block.h
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Basic sha256-based blockchain block object declaration file
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>

using std::string;

class Block
{
    public:
        string sPrevHash;   // Hash of the previous block in the chain

        Block(uint32_t nIndexIn, const string &sDataIn);    // Constructor (takes target index and data)
        string getHash();                                   // Return this block's hash
        string getData();                                   // Return this block's data
        void mineBlock(uint32_t nDifficulty);               // Mine a new block at a given difficulty

    private:
        uint32_t nIndex;    // Block index
        int64_t nNonce;     // Cryptographic nonce
        string sData;       // Data payload
        string sHash;       // The block's current hash
        time_t tTime;       // Time, used for Proof of Work hash

        string calculateHash() const;   // Create a hash of this block
};

#endif

//  sha256 hashing code adapted from Olivier Gay <olivier.gay@a3.epfl.ch> 
//  under a CC Attribution-ShareAlike 3.0 License
//      source: http://www.zedwood.com/article/cpp-sha256-function on 4/24/2021

#ifndef SHA256_H
#define SHA256_H

#include <string>
 
using std::string;

class SHA256
{
    protected:
        typedef unsigned char uint8;
        typedef unsigned int uint32;
        typedef unsigned long long uint64;
    
        const static uint32 sha256_k[];
        static const unsigned int SHA224_256_BLOCK_SIZE = (512/8);

    public:
        void init();
        void update(const unsigned char *message, unsigned int len);
        void final(unsigned char *digest);
        static const unsigned int DIGEST_SIZE = ( 256 / 8);
    
    protected:
        void transform(const unsigned char *message, unsigned int block_nb);
        unsigned int m_tot_len;
        unsigned int m_len;
        unsigned char m_block[2*SHA224_256_BLOCK_SIZE];
        uint32 m_h[8];
};
 
string sha256(std::string input);
 
#define SHA2_SHFR(x, n)    (x >> n)
#define SHA2_ROTR(x, n)   ((x >> n) | (x << ((sizeof(x) << 3) - n)))
#define SHA2_ROTL(x, n)   ((x << n) | (x >> ((sizeof(x) << 3) - n)))
#define SHA2_CH(x, y, z)  ((x & y) ^ (~x & z))
#define SHA2_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SHA256_F1(x) (SHA2_ROTR(x,  2) ^ SHA2_ROTR(x, 13) ^ SHA2_ROTR(x, 22))
#define SHA256_F2(x) (SHA2_ROTR(x,  6) ^ SHA2_ROTR(x, 11) ^ SHA2_ROTR(x, 25))
#define SHA256_F3(x) (SHA2_ROTR(x,  7) ^ SHA2_ROTR(x, 18) ^ SHA2_SHFR(x,  3))
#define SHA256_F4(x) (SHA2_ROTR(x, 17) ^ SHA2_ROTR(x, 19) ^ SHA2_SHFR(x, 10))
#define SHA2_UNPACK32(x, str)                 \
{                                             \
    *((str) + 3) = (uint8) ((x)      );       \
    *((str) + 2) = (uint8) ((x) >>  8);       \
    *((str) + 1) = (uint8) ((x) >> 16);       \
    *((str) + 0) = (uint8) ((x) >> 24);       \
}
#define SHA2_PACK32(str, x)                   \
{                                             \
    *(x) =   ((uint32) *((str) + 3)      )    \
           | ((uint32) *((str) + 2) <<  8)    \
           | ((uint32) *((str) + 1) << 16)    \
           | ((uint32) *((str) + 0) << 24);   \
}

#endif