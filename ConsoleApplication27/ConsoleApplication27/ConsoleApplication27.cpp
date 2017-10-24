#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int MAX_TOPPINGS = 5;

class PizzaOrder
{
   static const string TOPPING1;
   static const string TOPPING2;
   static const string TOPPING3;
   static const string TOPPING4;
   static const string TOPPING5;
   static const string SMALL;
   static const string MEDIUM;
   static const string LARGE;
   static const double smallPrice;
   static const double mediumConvFactor; //Neither conversion factor
   static const double largeConvFactor;  //will be modded

   string listOfToppings;
   int size;
   string toppings[MAX_TOPPINGS];
   int numToppings;
public:
   static const string toppingsOffered[MAX_TOPPINGS];
   static const double toppingBaseCost;
   static const double basePrice;

   PizzaOrder();
   PizzaOrder(int size);
   //fin
   bool addTopping(string topping);
   bool addTopping(int n);
   //fin
   bool setSize(int size);
   int getSize();
   //fin
   double getPrice();
   string stringizeSize();
   double convFactor(int size);
   //unfin
   void getToppings(string &listOfToppings);
   void displayPizza();
   //fin
   bool setNumToppings(int toppings);
   int getNumToppings();

};

const string PizzaOrder::TOPPING1 = "extra cheese";
const string PizzaOrder::TOPPING2 = "bell pepper";
const string PizzaOrder::TOPPING3 = "onions";
const string PizzaOrder::TOPPING4 = "olives";
const string PizzaOrder::TOPPING5 = "pepperoni";
const string PizzaOrder::SMALL = "small";
const string PizzaOrder::MEDIUM = "medium";
const string PizzaOrder::LARGE = "large";
const double PizzaOrder::smallPrice = 1.00;
const double PizzaOrder::mediumConvFactor = 1.15;
const double PizzaOrder::largeConvFactor = 1.25;
const string PizzaOrder::toppingsOffered[MAX_TOPPINGS] = {TOPPING1, TOPPING2,
   TOPPING3, TOPPING4,TOPPING5};
const double PizzaOrder::toppingBaseCost = 2.00;
const double PizzaOrder::basePrice = 10.00;

PizzaOrder::PizzaOrder()
{
   size = 0;
   numToppings = 0;
}

PizzaOrder::PizzaOrder(int size)
{
   if (setSize(size))
      this->size = size;
   numToppings = 0;
}

int PizzaOrder::getSize()
{
   return size;
}

int PizzaOrder::getNumToppings()
{
   return numToppings;
}

double PizzaOrder::getPrice()
{
   return (convFactor(size) * ((numToppings * toppingBaseCost) + basePrice));
}

double PizzaOrder::convFactor(int size)
{
   switch(size)
   {
      case 0:
         return smallPrice;
         break;
      case 1:
         return mediumConvFactor;
         break;
      case 2:
         return largeConvFactor;
         break;
   }
}

string PizzaOrder::stringizeSize()
{
   switch(size)
   {
      case 0:
         return SMALL;
         break;
      case 1:
         return MEDIUM;
         break;
      case 2:
         return LARGE;
         break;
   }

}


bool PizzaOrder::setNumToppings(int toppings)
{
   if ((toppings <= 5) && (toppings >= 0))
   {
      numToppings = toppings;
      return true;
   }
   return false;
}


bool PizzaOrder::setSize(int size)
{
   if ((size >= 0) && (size <= 2))
   {
      this->size = size;
      return true;
   }
   return false;
}

bool PizzaOrder::addTopping(string topping)
{
   if (numToppings < MAX_TOPPINGS)
   {
      toppings[(++numToppings)] = topping;
      return true;
   }
   return false;
}

bool PizzaOrder::addTopping(int n)
{
   if (numToppings <= MAX_TOPPINGS)
   {
      toppings[numToppings]= toppingsOffered[(n)];
      numToppings++;
      return true;
   }
   return false;
}

void PizzaOrder::getToppings(string &listOfToppings)
{
   for (int n = 0; n < numToppings; n++)
      listOfToppings = (listOfToppings + " " + toppings[n]);
}

void PizzaOrder::displayPizza()
{
   cout << "The pizza is:" << " ";
   cout << stringizeSize() << " ";
   string listOfToppings;
   getToppings(listOfToppings);
   cout << listOfToppings;
//   for (int n = 0; n < numToppings; n++)
//      cout << toppings[n] << " ";
   cout << " $" << getPrice() << endl;
}

int main()
{
   bool outState = true;
   bool inState = true;
   string outerInput;
   string innerInput;

   while(outState)
   {
      PizzaOrder aPizza;
      cout << "Pizza Size?(Small:0, Medium:1, Large:2, q to exit";
      cout << endl;
      getline(cin, outerInput);
      if (outerInput[0] == 'q' || outerInput[0] == 'Q')
      {
         outState = false;
         break;
      }
      if (outerInput[0] == '0')
         aPizza.setSize(0);
      if (outerInput[0] == '1')
         aPizza.setSize(1);
      if (outerInput[0] == '2')
         aPizza.setSize(2);

      while(inState)
      {
         if (aPizza.getNumToppings() == 5)
         {
            break;
         }
         cout << "Toppings?" << endl;
         for (int n = 1; n <= MAX_TOPPINGS; n++)
            cout << n << ":" << PizzaOrder::toppingsOffered[n] << " ";
         cout << endl << "q to quit" << endl;
         getline(cin, innerInput);
         if (innerInput[0] == 'q' || innerInput[0] == 'Q')
         {
            aPizza.displayPizza(); 
            break;
         }
         if (innerInput[0] == '1')
            aPizza.addTopping(1);
         if (innerInput[0] == '2')
            aPizza.addTopping(2);
         if (innerInput[0] == '3')
            aPizza.addTopping(3);
         if (innerInput[0] == '4')
            aPizza.addTopping(4);
         if (innerInput[0] == '5')
            aPizza.addTopping(5);
         aPizza.displayPizza(); 
      }
      cout << endl;
   }
   return 0;
}

/*RUN1
Pizza Size?(Small:0, Medium:1, Large:2, q to exit
0
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
1
The pizza is: small  bell pepper $12
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
2
The pizza is: small  bell pepper onions $14
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
3
The pizza is: small  bell pepper onions olives $16
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
4
The pizza is: small  bell pepper onions olives pepperoni $18
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
9
The pizza is: small  bell pepper onions olives pepperoni $18
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
9
The pizza is: small  bell pepper onions olives pepperoni $18
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
5
The pizza is: small  bell pepper onions olives pepperoni extra cheese $20

Pizza Size?(Small:0, Medium:1, Large:2, q to exit
1
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
2
The pizza is: medium  onions $13.8
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
4
The pizza is: medium  onions pepperoni $16.1
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
4
The pizza is: medium  onions pepperoni pepperoni $18.4
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
q
The pizza is: medium  onions pepperoni pepperoni $18.4

Pizza Size?(Small:0, Medium:1, Large:2, q to exit
2
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
3
The pizza is: large  olives $15
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
3
The pizza is: large  olives olives $17.5
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
3
The pizza is: large  olives olives olives $20
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
3
The pizza is: large  olives olives olives olives $22.5
Toppings?
1:bell pepper 2:onions 3:olives 4:pepperoni 5:extra cheese
q to quit
3
The pizza is: large  olives olives olives olives olives $25

Pizza Size?(Small:0, Medium:1, Large:2, q to exit
q
Press any key to continue . . .


*/