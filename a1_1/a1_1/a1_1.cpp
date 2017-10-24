// a1_1.cpp : Defines the entry point for the console application.
/* Myron Pow, Dave Harden, CS2C, 1/13/16, subsetSum Problem
Meant to be a simple solution to subset sum problem in order to illustrate
the efficiency of  different kinds of algorithms.
This one is of order 2^n
subset sum is NP complete, aka super slow, as all possibilites must be checked
aka there is no way to directly find the answer

This version is broken, and only works in one case.
*/
#include <iostream>
#include <vector>
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







  int main() {
    int TARGET = 180;
    vector<int> dataSet;    
    vector<Sublist> choices;
    vector<Sublist>::iterator iter, iterBest;    
    int k, j, numSets, max, masterSum;
    bool foundPerfect;
    dataSet.push_back(2);
    dataSet.push_back(1);
    dataSet.push_back(2);
    dataSet.push_back(1);
    dataSet.push_back(2);
    dataSet.push_back(1);
    dataSet.push_back(2);
    dataSet.push_back(1);
    dataSet.push_back(1);
    dataSet.push_back(1);
    dataSet.push_back(17);

    choices.clear();
    cout << "Target time: " << TARGET << endl;
    
masterSum = 0;
vector<int>::iterator iter1;
  for( iter1 = dataSet.begin(); iter1 != dataSet.end(); iter1++)
          masterSum += *iter1;
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
        if (Col.getSum()+dataSet[j] <= TARGET)
          Col.addItem(j);
      else
          j++; // skip to next element
  }
    iterBest->showSublist();
    return 0;
} 





  //RUN 1
  // The only case I could get working properly was maxSum < target case. 
  //Can't get "loop over all elements, L that already are members of Col"
  // or step 3 to work properly
  /*
  Target time: 180
List insufficient to meet target
Press any key to continue . . .
*/