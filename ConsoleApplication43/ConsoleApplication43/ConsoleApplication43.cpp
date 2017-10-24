
/*Myron Pow, Dave Harden, 1/27/2016, Assignment 3.2
Order of Matrix multiplication.
This is a global implementation of matrix multiplication, and includes a function
for display

I'm pretty sure I don't need to describe the global functions here, as this is hardly
a proper header file

Given the context of this assignment, giving the computer spec's is in order
Processor: Intel(R) Core(TM) i7-4810MQ CPU @ 2.80 GHz
RAM: 8.00 GB

Answer to the estimate of order is after the run, as requested.
ANSWERS TO QUESTIONS:
1 MINIMUM
Minimum number of MAT_SIZE to return a time would be 47, at 0.001 seconds

2 TABLE: (it's not really a table cuz you can't format stuff nicely in here)
Size, Time(sec)
47, 0.001
94, 0.003
188, 0.028
376, 0.268
752, 2.587
1504, 38.958
3008, 469.133
6016, 3121.19
12032, WON'T RUN IT(I don't want to spend a day running this)

3 MAXIMUM
I'm going to guess that the next iteration of 12032 is going to take over half a day.
Thus, for practical purposes 12032 is my maximum number.

4. ANALYSIS
Since I doubled size every row down the table, if the function was operating at 
n^3, the time should increase by a factor of 8 per row. That is clearly not the case
as the growth at the end of the table appears to be increasing by a factor of >10
Which implies an O() which is greater than cubic order, but less than quadratic order
(since its greater then a factor of 8(2^3), but less than 16(2^4).
So my estimates at the beginning were incorrect.
*/
#include <iostream>
#include <time.h>
using namespace std;

int const MAT_SIZE = 47;
typedef float* DynMat[MAT_SIZE];

DynMat mDyn, nDyn, ansDyn;

//See definition for details
void matMultDyn( const DynMat & matA,  const DynMat & matB, 
                DynMat & matC, int size);


//See definition for details
void matShowDyn( const DynMat & matA, int start, int size);


int main()
{
    int r, c;
    clock_t startTime, stopTime;
    float randFrac;
    int randRow, randCol, smallPercent;

    // non-sparse dynamic matrix
    DynMat matDyn, matDynAns;


   // allocate rows and initialize to 0
    for (r = 0; r < MAT_SIZE; r++)
    {
        matDyn[r] = new float[MAT_SIZE];
        matDynAns[r] = new float[MAT_SIZE];
        for (c = 0; c < MAT_SIZE; c++)
        {
            matDyn[r][c] = 0;
            matDynAns[r][c] = 0;
        }
    }

   // generate small% non-default values bet .1 and 10
    smallPercent = MAT_SIZE/20. * MAT_SIZE;  // div by 20. means 5%, of course
    for (r = 0; r < smallPercent; r++)
    {
        randRow = (rand() % MAT_SIZE);
        randCol = (rand() % MAT_SIZE);
        randFrac = (float)((rand() % 100)/(float)100);
        //matDyn[(rand() % MAT_SIZE)][(rand() % MAT_SIZE)] = (float)((rand() % 100)/(float)100);
        matDyn[randRow][randCol] = randFrac;
    }

    // 10x10 submatrix in lower right
    matShowDyn(matDyn, MAT_SIZE - 10, 10);

    startTime = clock();  // ------------------ start
    matMultDyn(matDyn, matDyn, matDynAns, MAT_SIZE);
    stopTime = clock();  // ---------------------- stop

    matShowDyn(matDynAns, MAT_SIZE - 10, 10);
    cout << "\nSize = " <<  MAT_SIZE << " Dyn Array Mult Elapsed Time: " 
        << (double)(stopTime - startTime)/(double)CLOCKS_PER_SEC 
        << " seconds." << endl << endl;

    // clean up
    for (r = 0; r < MAT_SIZE; r++)
    {
        delete[] matDyn[r];
        delete[] matDynAns[r];
    }
    cout << endl;
}






/* This does matrix multiplication for two dynamic matricies of a specific size
PRE: Two matricies to be multiplied, a blank matrix to fill as the result, and size
POS: A matrix that is the result of multiplying matrix a by matrix b
*/
void matMultDyn( const DynMat & matA,  const DynMat & matB, 
                DynMat & matC, int size)
{
    int row, col;
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            for (int prod = 0; prod < size; prod++)
            {
                matC[row][col] = matC[row][col] + (matA[row][prod] * matB[prod][col]);
            }
        }
    }
}






/*This displays a dynamic array of type DynMat
This is a matrix whose lower left corner is start, and is of dimensions
size * size
PRE:dynamic matrix, starting point, and a size
POS:Displayed matrix, 2 lines of whitespace

Notes:
    cout << endl << endl;
The last line(above) is to create space between matrices, but would
preferably be contained within the main, so as to keep the modularity of the
function
*/
void matShowDyn( const DynMat & matA, int start, int size)
{
    for (int i = start; i < (start + size); i++) 
    {
        for (int j = start; j < (start + size); j++)
        {
            cout << matA[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
}






/*RUN(only the hour long one)
0       0       0       0.74    0       0       0       0       0       0

0       0       0       0       0       0       0       0       0       0

0       0       0       0       0       0       0       0       0       0

0       0       0       0       0.88    0       0       0       0       0

0       0       0       0       0       0       0       0       0.86    0

0       0       0       0       0       0       0       0       0       0

0       0       0       0       0       0       0       0       0       0

0       0       0       0.14    0       0       0       0       0       0

0       0.57    0       0       0       0       0       0       0       0

0.39    0       0       0       0       0       0       0       0       0



2.2972  2.8346  1.8103  3.2468  3.5255  2.5594  1.4672  3.2457  3.3402  2.6218

1.9189  1.3643  3.6685  0.909   4.1412  3.7854  2.3722  3.2732  1.7984  4.6316

5.7777  2.8738  1.8293  2.5489  2.9497  5.2443  3.1645  2.8363  4.4082  3.5355

3.1568  2.8738  3.3708  2.3115  2.6428  3.894   1.8211  2.5524  2.7385  1.7977

3.8726  3.8925  1.211   1.9221  1.2316  2.7123  4.0106  2.3786  3.297   2.3929

1.1117  3.2064  3.3233  3.7997  3.6825  1.8944  3.2695  1.9415  4.1473  1.8839

2.2607  3.3474  3.5217  2.3317  1.8152  2.791   1.3315  3.9899  2.3687  1.2961

2.6505  3.3464  3.3053  3.4631  2.0679  1.7412  3.2769  3.1562  2.3552  2.4098

1.6291  0.6708  2.2691  5.1074  1.3247  2.5668  1.8866  2.2739  2.7539  2.7876

2.5162  2.4174  2.3155  2.5372  4.6415  1.1469  1.5781  2.9648  3.4528  3.5893




Size = 6016 Dyn Array Mult Elapsed Time: 3121.19 seconds.


Press any key to continue . . .
*/



/* Theoretical O()
I'm going to say that it will require 3 nested for loops, one for row,s one for columns,
and one to put it into the reference matrix, which according to the lesson should compound
the time it takes to run. Since each pass can go up to N times, order is O(N^3).
(N should be MAT_SIZE*MAT_SIZE I think).

Must the order always be written in terms of N only?

I think that the theta estimation is also n^3, since there is no shortcut
for the sections of the matrices that must be multiplied. The lesson also states
that Theta() is O() when it is always the worst case solution. Seeing as there 
is no "better" ending case, it must be equal, or Theta(N^3). Even if an empty matrix is
squared, it's still going to crunch over the entire matrix.

*/
