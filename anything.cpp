#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
using namespace std;

int ReadNumber_Of_Elements(string message)
{
    int number;
    cout << message << endl;
    cin >> number;
    return number;
}
int ReandomNumber(int from, int to)
{
    int random;
    random = rand() % (to - from + 1) + from;
    return random;
}
//changing some rules

void Fill_Random_Array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = char(ReandomNumber(48, 57));
    }
}
void Print_Random_Array(int array[], int size)
{
    cout << "Random Array For " << size << " Elements Is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
int FindNumberInArray(int array[], int &size, int number)
{
    for (int i =0 ; i < size; i++)
    {
        if (array[i] == number)
        {
            return i;
        }
    }
    return -1;
}
bool IsNumberInArray(int array[], int size,int number)
{
    return (FindNumberInArray(array,size,number)!=-1);
}
int cheakNumberPostion(int array[], int size, int CheakNumber)

{
    int counter = 0 ;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == CheakNumber)
        {
            counter++;
            return i;
        }
    }
    return -1;
}
void CheakNumberINArray(int array[], int size, int CheakNumber)
{
    int position = cheakNumberPostion(array, size, CheakNumber);
    cout << "Number IS:" << CheakNumber << endl;
    if (position == -1)
    {
        cout << "Number Not Founded " << endl;
    }
    else
    {
        cout << "Number Founded At Postion" << position << endl;
        cout << "Number Founded At Order" << position + 1 << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL)); // Must
    int array[100];
    int size = ReadNumber_Of_Elements("Please Enter Size Of Array");
    Fill_Random_Array(array, size);
    Print_Random_Array(array, size);
    int searchNumber = ReadNumber_Of_Elements("\nPlease Enter Number To Search");
    CheakNumberINArray(array, size, searchNumber);
    return 0;
}
