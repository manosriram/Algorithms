#include <iostream>
#include <vector>

void printVector(std::vector<int> v)
{
    for (auto t : v)
    {
        std::cout << t << " ";
    }
    std::cout << std::endl;
    return;
}