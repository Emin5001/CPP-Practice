#include <string>
#include <cmath>

class Coin
{
    private:
        std::string sideUp; //holds either heads or tails
    public:
        Coin(); //randomly determines the side of the coin and assigns it to sideUp var
        void toss();  //randomly determines the side of the coin that is facing up, and sets up the sideUp var
        std::string getSideUp(); //returns sideUp var
};

Coin::Coin()
{
    srand(time(0));
    int random = rand() % 2 + 1;

    if (random==1)
        sideUp = "heads";
    else   
        sideUp = "tails";
};

void Coin::toss()
{
    int randFacingUp = rand() % 2 + 1;
    if (randFacingUp == 1)
        sideUp = "heads";
    else   
        sideUp = "tails"; 
};

std::string Coin::getSideUp() { return sideUp;};