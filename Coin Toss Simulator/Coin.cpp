#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "Coin.h"

using namespace std;

int main()
{   
    Coin coin;
    int amtOfHeads = 0, amtOfTails = 0;

    cout << "The side initially facing up is: " << coin.getSideUp() << ".\n";
    for (int i = 0; i < 20; i++)
    {
        cout << amtOfTails << endl;
        coin.toss();
        cout << "Now, the side facing up is: " << coin.getSideUp() << ".\n";
        if (coin.getSideUp() == "heads")
            amtOfHeads++;
        else    
            amtOfTails++;
    } 

    cout << "The amount of heads:       " << amtOfHeads << endl;
    cout << "The amount of tails:       " << amtOfTails;
    return 0;
}