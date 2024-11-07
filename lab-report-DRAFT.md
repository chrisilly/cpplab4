**Chris Culling**

Lab report for **assignment 4**

7 Nov 2024

# Exercise 1: Sorting whole numbers

## Exercise 1a: Sorting `vector`

#### Issue #1
Ran into an issue where, even though I'm seemingly generating a new random vector every time with `rand()`, the numbers are the same each run. When debugging, it seems like `rand()` is genuinely just predictably spitting out the same numbers in the same order.

> [!NOTE]
> This is because `rand()` is not random 🙂

#### Issue #2
```cpp
std::vector<int> numbers = GetRandomNumbers();
numbers = GetRandomNumbers(); // this crashes the program 😳
```

#### Issue #3

`std::random_shuffle` apparently does not exist despite `#include <algorithm>` 🤷

### Solution

To create the randomized vector:
```cpp
int size = 12;
std::vector<int> numbers;

for (int i = 0; i < size; i++)
{
    numbers.push_back(rand());
}
```

The problem here is that the numbers are random in a sense, but they will be the same every time the program runs because `rand()` isn't really random. But it works for our purposes, so let's move on.

#### SortRandomlyGeneratedNumbersInVector()
```cpp
std::vector<int> randomNumbers = GetRandomNumbers();
cout << "Random ";
PrintNumbers(randomNumbers);

std::sort(randomNumbers.begin(), randomNumbers.end());
cout << "Sorted ";
PrintNumbers(randomNumbers);
```
Output ✅
```
Random Numbers: 41 18467 6334 26500 19169 15724 11478 29358 26962 24464 5705 28145
Sorted Numbers: 41 5705 6334 11478 15724 18467 19169 24464 26500 26962 28145 29358
```

## Exercise 1b: Sorting `int[]`

Instead of `vector.push_back()`, I use pointer iteration to initialize the int array with random values.

```cpp
int* numbers = new int[size];

for(int* pointer = numbers; pointer != numbers + size; ++pointer)
{
    *pointer = rand();
}
```

Thank you [stackoverflow](https://stackoverflow.com/questions/5897319/how-to-use-stdsort-to-sort-an-array-in-c) for teaching me how to use `std::sort` with an `int array`. Although I couldn't get `std::begin()` and `std::end()` to work, my actual implementation, inspired by the same thread, seems simpler.

```cpp
std::sort(randomNumbers, randomNumbers + size);
```

#### SortRandomlyGeneratedNumbersInIntArray()

```cpp
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
```
Output ✅
```
Random c-array Numbers: 23281 16827 9961 491 2995 11942 4827 5436 32391 14604 3902 153 
Sorted c-array Numbers: 153 491 2995 3902 4827 5436 9961 11942 14604 16827 23281 32391
```

## Exercise 1c: Sorting `vector` in descending order

## Exercise 1d: Sorting `int[]` in descending order

# Exercise 2: Sorting the person register

## Exercise 2a: Sorting persons

## Exercise 2b: Sorting backwards by address

# Exercise 3

---

# Process, Notes, Reflections

