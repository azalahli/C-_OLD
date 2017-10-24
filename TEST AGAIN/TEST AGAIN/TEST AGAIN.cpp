
#include <iostream>
#include <vector>
using namespace std;

/*
class Sublist
{
public:
Sublist(vector<int> orig): originalObjects(orig) { }

int getSum() const;

vector<int> originalObjects;
void showSublist();
};

int Sublist::getSum() const {
int result = 0;
for(int i = 0; i < originalObjects.size(); i++) {
result += originalObjects[i];
}
return result;
}

*/
/*
class Sublist
{
public:
   Sublist(vector<int> *orig = NULL) 
      : sum(0), originalObjects (orig) { }
   Sublist addItem( int indexOfItemToAdd );
   void showSublist() const;
   int getSum() const {return sum;}
   int sumList();

private:
   int sum;
   int size;
   vector<int> *originalObjects;
   vector<int> indices;
};



int Sublist::sumList()  {
int result = 0;
for(int i = 0; i < size; i++) {
result += indices[i];
}
return result;
}



void Sublist::showSublist() const 
{

}
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
int TARGET = 180;
vector<int> dataSet;
vector<Sublist> choices;
vector<Sublist>::iterator iter, iterBest;
int /*k, j, numSets, max, */masterSum;
bool foundPerfect;
/*
dataSet.push_back(20);
dataSet.push_back(12); dataSet.push_back(22);
dataSet.push_back(15); dataSet.push_back(25);
dataSet.push_back(19); dataSet.push_back(29);
dataSet.push_back(18);
dataSet.push_back(11); dataSet.push_back(13); dataSet.push_back(17);
*/
dataSet.push_back(1);
dataSet.push_back(2);
dataSet.push_back(3);
dataSet.push_back(4);
dataSet.push_back(18);
choices.clear();

/*if (choices.getsum())*/
masterSum = 0;
vector<int>::iterator iter1;
  for( iter1 = dataSet.begin(); iter1 != dataSet.end(); iter1++)
      //cout << *iter1;
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


/*
int closestSoFar = 123456789; // Start with arbitrarily large number
vector<int> dummy; //used for constructor, will be overwritten
Sublist bestSoFar(dummy);
cout << "Target time: " << TARGET << endl;
vector<int> temp;
vector<int> indices;

for(int i = 0; i < dataSet.size(); i++) {
    for(int j = i; j < dataSet.size();j++) {
        for (int k = i; k <= j; k++) {
            temp.push_back(dataSet.at(k));
                                     }
Sublist s(temp);
int distance = s.getSum() - TARGET;
if(distance < 0)
distance = -distance;
if(distance < closestSoFar) {
    closestSoFar = distance;
    bestSoFar = s;
    }
temp.clear();
                                            }
                                         }

cout << "The closest subsequence sum to the target is: " << bestSoFar.getSum() << endl;
cout << "Entries: ";
for(int i = 0; i < bestSoFar.originalObjects.size(); i++) {
cout << bestSoFar.originalObjects.at(i) << " ";
}
return 0;
*/
}