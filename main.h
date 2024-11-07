#include "PersonRegister.h"
#include <vector>

std::vector<int> GetNumbers();
std::vector<int> GetRandomNumbers();
int* GetRandomIntArray();
void PrintNumbersInIntArray(int* numbers);
void PrintNumbers(std::vector<int> &numbers);
void SortNumbers(std::vector<int> &numbers);

void SortRandomlyGeneratedNumbersInVector(bool descending = false);
void SortRandomlyGeneratedNumbersInIntArray(bool descending = false);
void SortShuffledPersonRegister();
void RemoveEvenNumbersFromRandomNumbers();

bool Even(int i);
bool ReadRegister(PersonRegister &personRegister, std::string fileName);