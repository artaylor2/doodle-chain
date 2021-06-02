# Doodle Chain

Doodle chain is a basic blockchain library created while experimenting with basic entry levels concepts related to the subject.

I uploaded it here to make it easier to share with friends and migrate between computers. Definitely up for any suggestions folks for ways to improve it!

## Installation

Runs entirely on standard CPP libraries. Should compile fine by running **'make'** in the main directory.

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
