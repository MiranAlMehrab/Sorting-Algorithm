#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

void printArray(int *arr,int elementCounter)
{
	for(int i=0;i<elementCounter;i++) cout<<arr[i]<<' ';
	getch();
}


int getElementNumber(string fileName)
{
	ifstream iFile;
	iFile.open(fileName.c_str(),ios::in);
	if(!iFile.is_open())
	{
		cout << "Couldn't open file."<<endl;
		return 0;
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

void bubbleSort()
{
	cout <<"Enter your file name: ";
	string fileName="";
	cin >> fileName;

	int elementCounter= getElementNumber(fileName);
	int *arr = new int[elementCounter];
	int element = 0;

	ifstream iFile;
	iFile.open(fileName.c_str(),ios::in);
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
	for(int i=0;i<elementCounter-1;i++)
	{
		for(int j=elementCounter-1;j>i;j--)
		{
			if(arr[j]>arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printArray(arr,elementCounter);

}

int main()
{
	bubbleSort();
	return 0;
}