//Chaelsey Park
//Modified 2/28/2021
//user enters two separate shopping lists into TEXT FILES (.TXT).
//program inputs each text file into a separate set of arrays
//then displays both lists separately on the screen
//next, program merges (quantities/duplicates) and sort both lists (alphabetically)
//then outputs final list BOTH to the screen into new text file

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "functions.h"
#define ARR_SIZE 5
using namespace std;

int main() 
{
  cout << "Hello! Welcome to Sort Your Shopping List! " << endl << "Two shopping lists will be combined and sorted." << endl << endl;

  const int max = 1000; //specified max size (doesn't change)
  int currentSize = 0; //current number of items in array
  string items[max]; //list of items
  int quantities[max];   //list of quantities - parallel to items
  string currentItem = " "; //input data from user
  
  const int fileItems = 100;
  string fileList[fileItems];
  int lineNumber = 1;
  string item;
  string item_name;
  string Qty;

  ifstream inFile1("input1.txt");
  ifstream inFile2("input2.txt");
  ofstream outFile("sortedList.txt");

  cout << "Shopping List 1:" << endl;
  while(!inFile1.eof())
  {
    getline (inFile1, item_name, ',');
    getline (inFile1, Qty , '\n');
    cout << "currentItem #" << currentSize + 1 << ": ";
    
    items[currentSize] = item_name;
    quantities[currentSize] = std::stoi(Qty);

    ++currentSize;

    cout << item_name << ',' << Qty <<'\n';
    //outFile << item_name << ',' << Qty <<'\n';
  }

  cout << endl << "Shopping List 2:" << endl;
  while(!inFile2.eof())
  {
    getline (inFile2, item_name , ',');
    getline (inFile2, Qty , '\n');
    cout << "currentItem #" << currentSize + 1 << ": ";

    items[currentSize] = item_name;
    quantities[currentSize] = std::stoi(Qty);

    ++currentSize;
    
    cout << item_name << ',' << Qty <<'\n';
    //outFile << item_name << ',' << Qty <<'\n';
  }

  

      //check for duplicates (remove if found)
      for(int i = 0; i < currentSize; i++)
      {
        for(int j = i + 1; j < currentSize;)
        {
          if(toLowerCase(items[i]) == toLowerCase(items[j]))
          {
            for(int temp = j; temp < currentSize; temp++)
            {
              quantities[temp] = quantities[temp] + quantities[i]; //add duplicate quantities together
              quantities[i] = quantities[temp];
              items[temp] = items[temp + 1];

            //  cout << "currentItem**" << items[i]<< ": ";
            //  cout << "currentsize" << std::to_string(currentSize)<< ": ";
            //  cout << "i&&&" << std::to_string(i)<< ": ";
              
    
              currentSize--;
            }   
          } 
          else
          {
            j++;
          }
        }
      }
    

    int var;
    bubbleSort(items, currentSize, var, quantities);
    cout << endl << "Sorted Shopping List: ";
    for(int i = 0; i < currentSize; i++)
    {
      cout << endl << i + 1 << ") " << quantities[i] << " " << items[i];
      outFile << items[i] << ',' << quantities[i] <<'\n';

    }
    outFile.close();

  string searchItem;
  cout << endl << endl << "Enter the name of the item you would like to search for: ";
  cin >> searchItem;
  cout << "Your item was found at " << sequentialSearch(items, currentSize, searchItem) << ".";
}