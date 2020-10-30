
// execute program for exactely x miliseconds
#include<chrono>

void func() { 
    auto start = chrono::steady_clock::now();
    if (chrono::steady_clock::now() - start > std::chrono::milliseconds(6000))
        break;
}

// uniforma rand generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    
int num = uniform_int_distribution<int>(0, 10)(rng); // number in [0, 10]