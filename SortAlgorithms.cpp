#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 100
#define SCOPE 100
class Sort
{
private:
	int array[SIZE];

public:
	Sort()
	{
		time_t t;
		srand(time(&t));
		for (int i = 0; i < SIZE; i++)
			array[i] = rand() % SCOPE;
	}
	
	void printArray()
	{
		for (int i = 0; i < SIZE; i++)
			printf("%d. %d\n", i, array[i]);
	}

	void bubbleSort()
	{
		int tmp;
		for (int i = 0; i < SIZE - 1; i++) 
		{
			for (int j = 0; j < SIZE - i - 1; j++)
			{
				if (array[i] > array[i + 1]) 
				{
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
				}
			}
		}
	}

	void bubbleSortUpgraded() {
		int p_min, p_max = SIZE - 1, p, tmp;
		do {
			p = -1;
			for (int i = 0; i < p_max; i++) {
				if (array[i] > array[i + 1]) {

					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;

					if (p == -1) p_min = i;
					p = i;
				}
			}
			if (p_min > -1)p_min--;
			p_max = p - 1;
		} while (p > -1);
	}

	void QuickSort(int left, int right) {
		int i = (left + right) / 2;
		int pivot = array[i];
		int tmp;
		array[i] = array[right];
		int j = left;
		for (i = left;  i < right; i++) {
			if (array[i] < pivot) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				j++;
			}
		}
		array[right] = array[j];
		array[j] = pivot;

		if (j - 1 > left) QuickSort(left, j - 1);
		if (j + 1 < right) QuickSort(j + 1, right);
	}

	void InsertionSort() {
		int x, j;
		for (int i = SIZE - 2; i >= 0; i--) {
			j = i + 1;
			x = array[i];
			while (j <= SIZE - 1 && x > array[j]) {
				array[j-1] = array[j];
				j++;
			}
			array[j - 1] = x;
		}
	}

	void Merge(int ip, int is, int ik)
	{
		int pomArray[SIZE];
		int i1, i2, i;
		i1 = ip, i2 = is;
		for (int i = ip; i <= ik; i++) {
			if ((i2 <= ik && array[i1] > array[i2]) || is == i1) {
				pomArray[i] = array[i2++];
			}
			else {
				pomArray[i] = array[i1++];
			}
		}
		for (int i = ip; i <= ik; i++) {
			array[i] = pomArray[i];
		}
	}
	
	void MergeSort(int ip, int ik) {
		int is = (ip + ik + 1) / 2;
		if (is - ip > 1)MergeSort(ip, is - 1);
		if (ik - is > 0)MergeSort(is, ik);
		Merge(ip, is, ik);
	}
	void SelectionSort() {
		int min, tmp;
		for (int j = 0; j < SIZE-1; j++) {
			min = j;
			for (int i = j + 1; i < SIZE; i++) {
				if (array[i] < array[min]) {
					min = i;
				}
			}
			tmp = array[min];
			array[min] = array[j];
			array[j] = tmp;
		}
	}
	void heapify(int n,int i)
	{
		int tmp;
		int largest = i;  // Initialize largest as root
		int l = 2 * i + 1;  // left = 2*i + 1
		int r = 2 * i + 2;  // right = 2*i + 2

							// If left child is larger than root
		if (l < n - 1 && array[l] > array[largest])
			largest = l;

		// If right child is larger than largest so far
		if (r < n - 1 && array[r] > array[largest])
			largest = r;

		// If largest is not root
		if (largest != i)
		{
			tmp = array[largest];
			array[largest] = array[i];
			array[i] = tmp;

			// Recursively heapify the affected sub-tree
			heapify(n, largest);
		}
	}
	void HeapSort() {
		int tmp;
		//build heap
		for (int i = SIZE / 2 - 1; i >= 0; i--)
			heapify(SIZE, i);

		// One by one extract an element from heap
		for (int i = SIZE - 1; i >= 0; i--)
		{
			// Move current root to end
			tmp = array[0];
			array[0] = array[i]; 
			array[i] = tmp;

			// call max heapify on the reduced heap
			heapify(i, 0);
		}
	}
};

int main() {
	Sort obj;
	obj.printArray();
	printf("\n");
	//obj.MergeSort(0, SIZE - 1);
	//obj.bubbleSortUpgraded();
	//obj.QuickSort(0, SIZE - 1);
	//obj.InsertionSort();
	//obj.SelectionSort();
	obj.HeapSort();
	obj.printArray();
}