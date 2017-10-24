/* Myron Pow, CS2B, 7/18/2015, Dave Harden, a5_3.cpp
Program sorts a list of ints from lowest to highest
No input is provided by a user, as it is preprepared in a client,
and the output is printed list via loops
*/

#include <iostream>
#include <algorithm>
using namespace std;

void sortAscending(int *list, int sortProgress);
int minIndex(int *array, int sortProgress);


int main()
{
    cout << "UNSORTED" << endl;
    int test1[] = {7, 7, 5, 4, 0};
    for (int k = 0; k < (sizeof(test1)/sizeof(test1[0])) ; k++)
        cout << test1[k] << " ";
    cout << endl;
    cout << "SORTED" << endl;
    sortAscending(test1, 0);
    for (int k = 0; k < (sizeof(test1)/sizeof(test1[0])) ; k++)
        cout << test1[k] << " ";
    cout << endl;
    int test2[] = {123, 3 ,4 ,5 ,6};
    cout << "UNSORTED" << endl;
    for (int k = 0; k < (sizeof(test2)/sizeof(test2[0])); k++)
        cout << test2[k] << " ";
    cout << endl;
    sortAscending(test2, 0);
    cout << "SORTED" << endl;
    for (int k = 0; k < (sizeof(test2)/sizeof(test2[0])); k++)
        cout << test2[k] << " ";
    return 0;
}




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



/*RUN1
UNSORTED
7 7 5 4 0
SORTED
0 4 5 7 7
UNSORTED
123 3 4 5 6
SORTED
3 4 5 6 123 Press any key to continue . . .
*/