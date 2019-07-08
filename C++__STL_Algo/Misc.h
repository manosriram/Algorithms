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

void printVector(std::vector<int>::iterator itr1, std::vector<int>::iterator itr2)
{
    for (auto itr = itr1; itr != itr2; itr++)
    {
        std::cout << *itr << " ";
    }
}