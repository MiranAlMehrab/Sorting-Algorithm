#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int getElementNumber(string fileName)
{
	ifstream iFile;
	iFile.open(fileName.c_str());
	if(!iFile.is_open())
	{
		cout << "Couldn't open file."<<endl;
		return -1;
	}
	int elementCounter=0;
	int element = 0;

	while(!iFile.eof())
	{
		iFile >> element;
		elementCounter++;
	}
	iFile.close();
	return elementCounter;
}


void printArray(int *arr,int elementCounter)
{
	for(int i=0;i<elementCounter;i++) cout<<arr[i]<<' ';
	getch();
}


void insertionSort()
{
	cout <<"Enter your file name: ";
	string fileName;
	cin >> fileName;

	int elementCounter = getElementNumber(fileName);
	if(elementCounter==-1) exit(0);
	int *arr = new int[elementCounter];
	int element = 0;

	ifstream iFile;
	iFile.open(fileName.c_str());
	if(!iFile.is_open())
	{
		cout << "Couldn't open file."<<endl;
		return;
	}
	
	while(!iFile.eof())
	{
		iFile >> arr[element];
		element++;
	}

	////////////////////////Sorting Part//////////////
	for(int i=1;i<elementCounter;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(arr[j]>arr[j-1])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}

	printArray(arr,elementCounter);

}

int main()
{
	insertionSort();
	return 0;
}