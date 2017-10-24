



int Sublist::getSum() const {
int result = 0;
for(int i = 0; i < originalObjects.size(); i++) {
result += originalObjects[i];
}
return result;
}

int main()
{
int TARGET = 180;
vector<int> dataSet;
vector<Sublist> choices;
vector<Sublist>::iterator iter, iterBest;
int k, j, numSets, max, masterSum;
bool foundPerfect;

dataSet.push_back(20);
dataSet.push_back(12); dataSet.push_back(22);
dataSet.push_back(15); dataSet.push_back(25);
dataSet.push_back(19); dataSet.push_back(29);
dataSet.push_back(18);
dataSet.push_back(11); dataSet.push_back(13); dataSet.push_back(17);

choices.clear();

int closestSoFar = 10000; // Start with arbitrarily large number
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
}