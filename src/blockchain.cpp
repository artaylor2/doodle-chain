/**
 * @file blockchain.cpp
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Basic sha256-based blockchain definition file
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "blockchain.h"

using std::cout;
using std::endl;

/**
 * @brief Construct a new Blockchain::Blockchain object
 * 
 */
Blockchain::Blockchain(int diff)
{
    // Create a genesis block using emplace to run the constructor for the block
    vChain.emplace_back(Block(0, "Genesis Block"));
    
    // Initialize the hashing difficulty
    nDifficulty = diff;
}

/**
 * @brief Add a new block to the chain
 * 
 * @param newBlock The new block being added
 */
void Blockchain::addBlock(Block newBlock)
{
    // Hash the previous block and store it
    newBlock.sPrevHash = getLastBlock().getHash();
    
    // Mine a new block at current nDifficulty
    newBlock.mineBlock(nDifficulty);
    
    // Add block to the chain
    vChain.push_back(newBlock);
}

/**
 * @brief Return the last block in the chain
 * 
 * @return Block The chain's last block
 */
Block Blockchain::getLastBlock() const
{
    return vChain.back();
}

/**
 * @brief Display all blocks in the current chain and their contents
 * 
 */
void Blockchain::displayChain()
{
    for(int i = 0; i < vChain.size(); i++)
    {
        cout << "Block " << i << '/' << vChain.size() << endl 
             << "Contents: " << vChain[i].getData() << endl << endl;
    }
}