# Doodle Chain

Doodle chain is a basic blockchain library created while experimenting with basic entry levels concepts related to the subject.

It's designed to be straightforward, heavily commented, and is likely to undergo frequent and drastic alterations throughout the course of the project.

I uploaded it here to make it easier to share with friends and migrate between computers. Definitely up for any suggestions folks might have for ways to expand the scope and utility of the code.

## Installation

Run entirely on standard CPP libraries. Should compile fine by running **'make'** in the main directory.

## Usage

```cp
#include "blockchain.h"

int main()
{
   Blockchain newChain = Blockchain(int difficulty)

   newChain.addBlock(int index, string data);
   newChain.displayChain();

   return;
}
```
