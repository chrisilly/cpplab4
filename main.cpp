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

const int size = 12;

int main()
{
    std::cout << "Hello World!" << endl;

    // Exercise 1a
    SortRandomlyGeneratedNumbersInVector();

    // Exercise 1b
    SortRandomlyGeneratedNumbersInIntArray();

    // std::random_shuffle(numbers.begin(), numbers.end()); // random shuffle doesn't exist
}

/// @brief Exercise 1a
void SortRandomlyGeneratedNumbersInVector()
{
    // 1.
    std::vector<int> randomNumbers = GetRandomNumbers();

    // 2.
    cout << "Random ";
    PrintNumbers(randomNumbers);
    
    // 3.
    std::sort(randomNumbers.begin(), randomNumbers.end());

    // 4.
    cout << "Sorted ";
    PrintNumbers(randomNumbers);
}

/// @brief Exercise 1b
void SortRandomlyGeneratedNumbersInIntArray()
{
    // 1.
    int* randomNumbers = GetRandomIntArray();

    // 2.
    cout << "Random c-array ";
    PrintNumbersInIntArray(randomNumbers);

    // 3.
    std::sort(randomNumbers, randomNumbers + size);

    // 4.
    cout << "Sorted c-array ";
    PrintNumbersInIntArray(randomNumbers);

    delete randomNumbers;
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

/// @brief CALL `delete` ON WHATEVER THIS GOES TO WHEN DONE WITH IT
/// @return c-style int array (ALLOCATED ON HEAP) with random values
int* GetRandomIntArray()
{
    int* numbers = new int[size];

    for(int* pointer = numbers; pointer != numbers + size; ++pointer)
    {
        *pointer = rand();
    }

    return numbers;
}

std::vector<int> GetNumbers()
{
    // int size = 12; // this can (and probably should) be a parameter, or a global constant/variable
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

void PrintNumbersInIntArray(int* numbers)
{
    cout << "Numbers: ";
    for(int* pointer = numbers; pointer != numbers + size; ++pointer)
        cout << *pointer << " ";
    cout << endl;
}