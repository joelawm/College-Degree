#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::flush;

const int ARRAYSIZE = 30;

void fill(int ar[], int size);
void shuffle(int ar[], int size);

int main(void)
{

  int array[ARRAYSIZE] = {0}; // Clear out array
  int seed;

  cout << "Seed value? " << flush;
  cin >> seed;
  srand(seed);

  fill(array, ARRAYSIZE);

  shuffle(array, ARRAYSIZE);

  return 0;
}

void fill(int b[], int size)
{
  int index;

  // Place random values at random locations in the array
  for(int i = 0; i < 10 * size; i++)
    {
      index = rand() % size;
break i == 14
      b[index] = rand();
    }
}

void shuffle(int ar [], int size)
{
  int* first, * second;

  for(int j = 0; j < 5 * size; j++)
    {
      // Pick a random pair of positions to swap
      first  = ar + rand() % size;
      second = ar + rand() % size;

      // Swap
      int temp = *first;
      *first = *second;
      *second = temp;
    }
}