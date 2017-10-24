/*    int findSmallest(int list[], int size);

int indexSmall(int *list, int indexCount)
{
    int size;
    size = sizeof(list) / sizeof(list[0]);
    int temp = list[indexCount];
    int smallIndex = indexCount;
    for (int k = 0; k < size; ++k)
    {
        if (list[temp] > list[k])
        {
            temp = list[k];
            smallIndex = k;
        }
    }
    return smallIndex;
}

void sortSmall(int *list, int indexCount)
{
    int size;
    int smallStorage;
    cout << "sizeof";
    size = sizeof(list) / sizeof(list[0]);
    cout << "break2";
    if (size == indexCount)
        return;
    int minIndex = indexSmall(list, indexCount);
    smallStorage = list[minIndex];
    list[minIndex] = list[indexCount];
    list[indexCount] = smallStorage;
    sortSmall(list, ++indexCount);
}
/*
int arraySize(int *list)
{
    int listsize;
    listsize = (sizeof(list));
    cout << listsize;
    return listsize;
}

int main()
{
    int ih[5] = {1,34,8,4,11};
    int indexCount = 0;
    cout << "hi" << endl;

    cout << ((sizeof(ih)/sizeof(*ih)));
    sortSmall(ih, indexCount);
    cout << "do u sort" << endl;
     for (int i = 0; i < 5; i++)
        cout << ih[i] << ' ';
     return 0;

}
void sortingIntegers(int *list, int left, int size);
int smallestIndex(int *array, int left, int size);


int main()
{
    int numbers[] = {8, 2, 5, 1, 0};
    cout << sizeof(numbers) / sizeof numbers[0];
    sortingIntegers(numbers, 0, 5);
    for (int i=0;i<5;i++)
        cout << numbers[i] << ' ';
    return 0;
}

void sortingIntegers(int *list, int left, int size) {
    if (left == size)
        return;
    int smallest = smallestIndex(list, left, size);
    int c = list[smallest];
    list[smallest] = list[left];
    list[left] = c;
    sortingIntegers(list, left+1 ,size);
}

int smallestIndex(int *array, int left, int size) {
    int smallest = array[left];
    int smIndex = left;
    for (int i = left+1; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
            smIndex = i;
        }
    }
    return smIndex;
}
*/

#include <iostream>
#include <algorithm>
using namespace std;

void sortAscending(int *list, int sortProgress);
int minIndex(int *array, int sortProgress);

void sortAscending(int *list, int sortProgress)
{
    int size = (sizeof(list) + 1);
    if (sortProgress == size)
        return;
    int smallestIndex = minIndex(list, sortProgress);
    int smallestValue = list[smallestIndex];
    list[smallestIndex] = list[sortProgress];
    list[sortProgress] = smallestValue;
    sortAscending(list, ++sortProgress);
}

int minIndex(int *list, int sortProgress)
{
    //Intrestingly enough, sizeof(list)/sizeof(list[0]) will not give
    //correct size inside the program due to pointer value
    //works properly outside though
    int size = (sizeof(list) + 1);
    int minVal = list[sortProgress];
    int minIndex = sortProgress;
    for (int k = ++sortProgress; k < size; k++) 
    {
        if (minVal > list[k]) 
        {
            minVal = list[k];
            minIndex = k;
        }
    }
    return minIndex;
}

int main()
{
    int test1[] = {7, 7, 5, 4, 0, 6 ,6, 8};
    sortAscending(test1, 0);
    for (int k = 0; k < (sizeof(test1)/sizeof(test1[0])) ; k++)
        cout << test1[k] << " ";
    cout << endl;
    int test2[] = {123, 3 ,4 ,5 ,6 ,7, 23};
    sortAscending(test2, 0);
    cout << "SORTED" << endl;
    for (int k = 0; k < (sizeof(test2)/sizeof(test2[0])); k++)
        cout << test2[k] << " ";
    return 0;
}