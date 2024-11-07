#include "main.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <random>
#include <functional>

// using namespace std;
using std::cout;
using std::endl;

int main()
{
    std::cout << "Hello World!" << endl;

    // std::vector<int> numbers = GetNumbers();
    // PrintNumbers(numbers);

    std::vector<int> randomNumbers = GetRandomNumbers();
    cout << "Random ";
    PrintNumbers(randomNumbers);
    
    std::sort(randomNumbers.begin(), randomNumbers.end());
    cout << "Sorted ";
    PrintNumbers(randomNumbers);

    // std::random_shuffle(numbers.begin(), numbers.end()); // random shuffle doesn't exist
}

std::vector<int> GetRandomNumbers()
{
    int size = 12;
    std::vector<int> numbers;

    for (int i = 0; i < size; i++)
    {
        numbers.push_back(rand());
    }

    return numbers;
}

std::vector<int> GetNumbers()
{
    int size = 12; // this can (and probably should) be a parameter, or a global constant/variable
    std::vector<int> numbers;

    for(int i = 1; i <= size; i++)
    {
        numbers.push_back(i);
    }

    return numbers;
}

void SortNumbers(std::vector<int> &numbers)
{
    // Sort numbers
    // code here...
    // Print numbers
    PrintNumbers(numbers);
}

void PrintNumbers(std::vector<int> &numbers)
{
    cout << "Numbers: ";
    for(int number : numbers)
        cout << number << " ";
    cout << endl;
}