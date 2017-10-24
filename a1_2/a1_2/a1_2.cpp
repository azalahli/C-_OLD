// a1_2.cpp : Defines the entry point for the console application.
//
/* Myron Pow, Dave Harden, CS2C, 1/13/16, subsetSum Problem
Subset sum for a series of itunes songs.
Doesn't work any better than before
*/
#include <iostream>
#include <vector>
#include "iTunes.h"
using namespace std;

/* 
    Sublist(vector<int> *orig = NULL)
        : sum(0), originalObjects (orig) {}
Creates an empty sublist;

    Sublist addItem(int index);
takes an element and adds that to the sublist(element&sum of sublist)

    void showSublist() const;
displays sublist

    int getSum() const { return sum; }
Accessor, retrieves sum of sublist
*/


class Sublist
{
public:
    Sublist(vector<int> *orig = NULL)
        : sum(0), originalObjects (orig) {}
    Sublist addItem(int index);
    void showSublist() const;
    int getSum() const { return sum; }

private:
   int sum;
   vector<int> *originalObjects;
   vector<int> indices;
};






Sublist Sublist::addItem(int index)
{
    Sublist temp;
    temp.sum = this->sum + (*originalObjects)[index];
    temp.indices.push_back(index);
    return temp;
}






void Sublist::showSublist() const
{
  for(int i = indices.size(); i < indices.size(); i++)
    cout << this->indices[i];
}






int main()
{
   const int TARGET = 3600;
   vector<iTunesEntry> dataSet;
   vector<Sublist> choices;
   vector<Sublist>::iterator iter, iterBest;
   int k, j, numSets, max, array_size, masterSum;
   bool foundPerfect;

   // read the data
   iTunesEntryReader tunes_input("itunes_file.txt");
   if (tunes_input.readError())
   {
      cout << "couldn't open " << tunes_input.getFileName() 
         << " for input.\n";
      exit(1);
   }

   // time the algorithm -------------------------
   clock_t startTime, stopTime; 
   startTime = clock();

   // create a vector of objects for our own use:
   array_size = tunes_input.getNumTunes();
   for (int k = 0; k < array_size; k++)
      dataSet.push_back(tunes_input[k]);

   cout << "Target time: " << TARGET << endl;

masterSum = 0;
vector<iTunesEntry>::iterator iter1;
int library=0;
  for( iter1 = dataSet.begin(); iter1 != dataSet.end(); iter1++)
      library++;
  for (int i = 0; i < library; i++)
          masterSum += iter1[i].getTime();
  if (TARGET > masterSum)
  {
      cout << "List insufficient to meet target" << endl;
      return 0;
  }
  Sublist Col; //default is already NULL
  for (int i = 0; i < dataSet.size(); i++)
      Col.addItem(i);
  for (int j = 1; j < dataSet.size(); j++)
  {
        if (Col.getSum() == TARGET)
    {
        Col.showSublist();
        cout << Col.getSum();
    }
        if (Col.getSum() + dataSet[j].getTime() <= TARGET)
          Col.addItem(j);
      else
          j++; // skip to next element
  }
   
   iterBest->showSublist();

   return 0; 
}