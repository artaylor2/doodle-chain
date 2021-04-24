/**
 * @file blockchain.h
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Basic sha256-based blockchain declaration file
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <iostream>
#include <vector>

#include "block.h"

using std::vector;

class Blockchain
{
    public:
        Blockchain(int diff);           // Constructor
        void addBlock(Block newBlock);  // Mine a new block and add it to the chain
        void displayChain();            // Print out the current state of the blockchain

    private:
        uint32_t nDifficulty;   // Mining difficulty for the chain
        vector<Block> vChain;   // Blockchain vector

        Block getLastBlock() const; // Getter for the chain's last block
};

#endif