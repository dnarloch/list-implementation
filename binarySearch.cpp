#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30
#define SCOPE 100
class BinarySearch
{
private: 
	int array[SIZE];

public:
	void fillArray()
	{
		time_t t;
		srand(time(&t));
		for (int i = 0; i < SIZE; i++)
		{
			array[i] = rand()%SCOPE;
			if (array[i] == -1)
				array[i] *= SIZE;
		}
	};

	void BubbleSortArray()
	{
		int tmp;
		for(int i = 0; i < SIZE - 1 ; i++)
			for (int j = 0; j < SIZE - i - 1; j++)
			{
				if (array[j] > array[j + 1]) {
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
				}
			}
	};
	int BinarySearchRecursive(int key, int start, int end)
	{
		int middle = (start + end) / 2;
		if (start > end)
			return -1;
		else if (array[middle] == key)
			return middle;
		else if (array[middle] > key)
			return BinarySearchRecursive(key, start, middle - 1);
		else
			return BinarySearchRecursive(key, middle + 1, end);
	};

	int Search(int key)
	{
		int start = 0;
		int end = SIZE - 1;
		int middle;
		while (start <= end) 
		{ 
			middle = (start + end) / 2;
			if (array[middle] == key)
				return middle;
			if (array[middle] > key)
				end = middle - 1;
			else
				start = middle + 1;
			
		}
		return -1;
	}
	void printArray() 
	{
		for (int i = 0; i < SIZE; i++)
			printf("%d.%d\n", i, array[i]);
	}
};

int main()
{
	time_t t;
	srand(time(&t));
	BinarySearch obj;
	obj.fillArray();
	obj.printArray();
	printf("\n");
	obj.BubbleSortArray();
	obj.printArray();
	int l = rand() % 100;
	printf("\nLook for: %d : Number's index in the array is: %d",
		l, obj.BinarySearchRecursive(l, 0, SIZE - 1));
	
	l = rand() % 100;
	printf("\nLook for: %d : Number's index in the array is: %d", l, obj.Search(l));

 }