#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
using namespace std;
enum PrimeNumber
{
  prime = 1,
  NotPrime = 2
};
//changing some rules

PrimeNumber cheak_Prime(int number)
{
  int m = number / 2;
  for (int i = 2; i < m; i++)
  {
    if (number % i == 0)
    {
      return PrimeNumber::NotPrime;
    }
  }
  return PrimeNumber::prime;
}
int ReadNumber_Of_Elements(string message)
{
  int number;
  cout << message << endl;
  cin >> number;
  return number;
}
int RandomNumbers(int from, int to)
{
  int random;
  random = rand() % (to - from + 1) + from;
  return random;
}
// void ReadArray(int array[], int &size)
// {
//   int counter = 1;
//   for (int i = 0; i < counter; i++)
//   {
//     array[i] = ReadNumber_Of_Elements("Please Enter A Number");
//     int cheak_To_add = ReadNumber_Of_Elements("Do You Want To Add More Numbers ? yes[1], No[0]");
//     if (cheak_To_add == 1)
//     {
//       counter++;
//     }
//     else
//     {
//       break;
//     }
//   }
//   size = --counter;
// }

void Normal_Print_Array(int array[], int &size)
{
  if (size == 0)
  {
    cout << "There Are Not Prime Numbers In Container" << endl;
  }
  else
  {
    cout << "Array For Length " << size << " Elements Is:" << "";
    for (int i = 0; i < size; i++)
    {
      cout << array[i] << " ";
    }
  }
}
void addarrayElement(int array[], int &size, int number) // الاساس do while loop
{
  size++; // legth Of Destnation Array
  array[size - 1] = number;
}
void IputNumberUserArray(int array[], int &size)
{
  bool addmore = true;
  do
  {
    addarrayElement(array, size, ReadNumber_Of_Elements("Please Enter a New Number"));
    cout << "Do You Want To Add More Numbers ? yes[1], No[0]" << endl;
    cin >> addmore;
  } while (addmore);
}
void Fill_Random_Array(int array[], int &size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = (RandomNumbers(48, 57));
  }
}
int FindNumberInArray(int array[], int &size, int number)
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] == number)
    
    {
      return i;
    }
  }
  return -1;
}
bool IsNumberInArray(int array[], int size, int number)
{
  return (FindNumberInArray(array, size, number) != -1);
}
void copy_unique_Numbers(int source[], int destnation[], int size1, int &size2)
{
  for (int i = 0; i < size1; i++)
  {
    if (!IsNumberInArray(destnation, size2, source[i]))
    {
      addarrayElement(destnation, size2, source[i]);
    }
  }
}

int main()
{
  srand((unsigned)time(NULL)); // Must
  int array1[100];
  int array2[100];
  int size1 = 0;
  int size2 = 0;
  size1 = ReadNumber_Of_Elements("Enter The Size Of Array1");
  Fill_Random_Array(array1, size1);
  Normal_Print_Array(array1, size1);
  copy_unique_Numbers(array1, array2, size1, size2);
  cout << "\nOnly Unique Numbers In Array Is:" << endl;
  Normal_Print_Array(array2, size2);

  return 0;
}
