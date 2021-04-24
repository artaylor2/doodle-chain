/**
 * @file main.cpp
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Basic implementation of blockchain using C++
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

 // Adapted from David Nash's tutorial
 //     source: <https://davenash.com/2017/10/build-a-blockchain-with-c/> on 4/24/2021

#include <iostream>

#include "blockchain.h"

using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
    // Create a difficulty integer
    int difficulty = 5;

    // Using the program's argc as the difficulty integer
    if(strtol(argv[1], nullptr, 0) > 0)
    {
        difficulty = strtol(argv[1], nullptr, 0);
    }
    // Otherwise default to 5
    else
    {
        cerr << "Invalid difficulty value passed as command line argument!" << endl << endl;
    }

    cout << "Creating a new blockchain at difficulty " << difficulty << '.' << endl << endl;
    cout << "note: To run with a different difficulty execute again with a positive integer argument" << endl << endl;
    
    // Create a new blockchain at current difficulty and mine three blocks
    Blockchain mainChain = Blockchain(5);

    cout << "Mining block 1:" << endl;
        mainChain.addBlock(Block(1, "Block 1 Data"));
    cout << "Mining block 2:" << endl;
        mainChain.addBlock(Block(2, "Block 2 Data"));
    cout << "Mining block 3:" << endl;
        mainChain.addBlock(Block(3, "Block 3 Data"));
    
    // Display the completed blockchain
    cout << endl;
    mainChain.displayChain();

    return 0;
}