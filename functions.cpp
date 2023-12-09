#include "functions.h"

void bubbleSort(string arr[], int size, int num, int quant[num])
{
  string temp; //variable to store index i
  num = 1000;
  int temp2; //variable to store quant

  for (int i = 0; i < size-1; i++)
  {
    for (int j = i + 1; j < size; j++) //j is a variable to hold index i + 1
    {
      if(arr[j] < arr[i]) //if index j > index i
      {
        temp = arr[i]; //temp = index i
        arr[i] = arr[j]; //index i = index j
        arr[j] = temp; //index j = temp
        temp2 = quant[i];
        quant[i] = quant[j];
        quant[j] = temp2;
      }
    }
  }
}

string toLowerCase(string str)
{
  for(int i=0; i<str.length(); ++i)
  {
    //if it is an upper case character 
    //(assumes it is a letter)
    if(str[i] < 97)
    {
      str[i] = str[i] + 32;
    }
  }
  
  return str;
}

int sequentialSearch(string items[], int itemsLength, string searchKey)
{
  int indexFound = -999;

  //use a for-loop to go through each item in the array one at a time 
  //each time we will ask if the item is a match to searchKey
  //if it is a match we will store that index
  for(int i=0; i<itemsLength; ++i) //i = index
  {
    if(items[i] == searchKey)
    {
      indexFound = i + 1;
    }
  }

  return indexFound;
}