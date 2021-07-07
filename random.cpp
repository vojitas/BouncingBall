#include "random.h"

unsigned int rand_i(unsigned int min, unsigned int max)
{
    static std::random_device rd;  //Will be used to obtain a seed for the random number engine
    static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<unsigned int> distrib(min, max);

    return distrib(gen);
}
