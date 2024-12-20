#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "main.h"
#include "Person.h"
#include "PersonRegister.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <random>
#include <functional>

// using namespace std;
using std::cout;
using std::endl;
using std::string;

const int size = 12;

int main()
{
    std::cout << "Hello World!" << endl;

    bool descending = true;

    // Exercise 1a
    SortRandomlyGeneratedNumbersInVector();

    // Exercise 1b
    SortRandomlyGeneratedNumbersInIntArray();

    // Excercise 1c
    SortRandomlyGeneratedNumbersInVector(descending);

    //Exercise 1d
    SortRandomlyGeneratedNumbersInIntArray(descending);

    // Exercise 2a + 2b
    SortShuffledPersonRegister();

    // Exercise 3
    RemoveEvenNumbersFromRandomNumbers();

    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
    _CrtDumpMemoryLeaks();

    // std::cin;
}

bool Even(int i) { return i%2==0; }

/// @brief Exercise 3
void RemoveEvenNumbersFromRandomNumbers()
{
    // 1. Create container with random numbers
    std::vector<int> randomNumbers = GetRandomNumbers();

    // 2. Print container
    cout << "Random ";
    PrintNumbers(randomNumbers);

    // 3. Remove even numbers with the help of STL (`remove_if` and `erase`)
    auto result = std::remove_if(randomNumbers.begin(), randomNumbers.end(), Even);
    randomNumbers.erase(result, randomNumbers.end());

    // 4. Print container again
    cout << "Removed EVEN ";
    PrintNumbers(randomNumbers);
}

/// @brief Exercise 2a + 2b
void SortShuffledPersonRegister()
{
    // 1.
    PersonRegister personRegister(size);
    ReadRegister(personRegister, "SortPersonsTest.txt");
    cout << "UNSORTED REGISTER" << endl;
    personRegister.Print();

    // 2.
    // `random_shuffle` was deprecated in C++14, so I'm using `shuffle` instead, which takes a generator as a parameter
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(personRegister.begin(), personRegister.end(), generator);

    // 3.
    cout << "SHUFFLED REGISTER" << endl;
    personRegister.Print();

    // 4.
    std::sort(personRegister.begin(), personRegister.end());

    // 5.
    cout << "SORTED REGISTER" << endl;
    personRegister.Print();
}

/// @brief Exercise 1a + 1c
void SortRandomlyGeneratedNumbersInVector(bool descending)
{
    // 1.
    std::vector<int> randomNumbers = GetRandomNumbers();

    // 2.
    cout << "Random ";
    PrintNumbers(randomNumbers);
    
    // 3.
    if(descending)
        std::sort(randomNumbers.rbegin(), randomNumbers.rend());
    else
        std::sort(randomNumbers.begin(), randomNumbers.end());

    // 4.
    cout << "Sorted "; if(descending) cout << "DESCENDING ";
    PrintNumbers(randomNumbers);
}

/// @brief Exercise 1b + 1d
void SortRandomlyGeneratedNumbersInIntArray(bool descending)
{
    // 1.
    int* randomNumbers = GetRandomIntArray();

    // 2.
    cout << "Random c-array ";
    PrintNumbersInIntArray(randomNumbers);

    // 3.
    if(descending)
    {
        auto greater = [](int x, int y){ return x>y; };

        std::sort(randomNumbers, randomNumbers + size, greater);
    }
    else
        std::sort(randomNumbers, randomNumbers + size);

    // 4.
    cout << "Sorted c-array "; if(descending) cout << "DESCENDING ";
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

bool ReadRegister(PersonRegister &personRegister, string fileName)
{
    string line;
    std::ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            while (line.length() == 0 && getline(myfile, line))
                ; // what?
            string name(line);
            string address;
            getline(myfile, address);
            // Person entry(name, address);
            personRegister.AddToRegister(&Person(name, address));
        }
        myfile.close();
        return true;
    }
    else 
    {
        cout << "Unable to open file";
        return false;
    }
}