#include "random.h"

static void initRandomSeed();

int randomInteger(int low, int high)
{
    initRandomSeed();
    double d = rand()/(double(RAND_MAX)+1);
    double s = d*(double(high) - low +1);
    return int(floor(low+s));
}

double randomReal(double low, double high)
{
    initRandomSeed();
    double d = rand()/(double(RAND_MAX)+1);
    double s = d*(high-low);
    return low+s;
}

bool randomChance(double p)
{
    initRandomSeed();
    return randomReal(0,1) < p;
}

void setRandomSeed(int seed)
{
    initRandomSeed();
    srand(seed);
}

static void initRandomSeed()
{
    static bool initialized = false;
    if(!initialized)
    {
        srand(int(time(NULL)));
        initialized = true;
    }
}
