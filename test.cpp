#include <iostream>

using namespace std;

void getInformation(int array[], int size);
void quickSort(int array[], int left, int right);

int main()
{
   freopen("input.txt","r",stdin);
   int number;
   cin >> number;
   int array[100];
   getInformation(array, number);
   quickSort(array, 0, number - 1);
   for (int i = 0; i < number; i++)
      cout << array[i] << " ";
   return 0;
}

void getInformation(int array[], int size)
{
   for (int i = 0; i < size; i++)
      cin >> array[i];
}
void quickSort(int array[], int left, int right)
{
   int pivot = array[(left + right) / 2];
   int i = left, j = right;
   while (i <= j)
   {
      while (array[i] < pivot)
         i++;
      while (array[j] > pivot)
         j--;
      if (i <= j)
      {
         swap(array[i], array[j]);
         i++;
         j--;
      }
   }
   if (i < right)
      quickSort(array, i, right);
   if (left < j)
      quickSort(array, left, j);
}