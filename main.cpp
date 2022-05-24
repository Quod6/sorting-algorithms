#include <Windows.h>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
T median(T value1, T value2, T value3)
{
	if ((value1 <= value2 && value2 <= value3) || (value3 <= value2 && value2 <= value1))
	{
		return value2;
	}

	if ((value2 <= value1 && value1 <= value3) || (value3 <= value1 && value1 <= value2))
	{
		return value1;
	}

	return value3;
}

template <typename T>
void qSort(T * array, int left, int right, int median)
{
	if (right - left <= median)
	{
		T temp;
		unsigned j;

		for (unsigned i = 0; i < right + 1; i++)
		{
			temp = array[i];

			for (unsigned j = i - 1; j >= 0 && array[j] > temp; j--)
			{
				array[j + 1] = array[j];
			}

			array[j + 1] = temp;
		}

		return;
	}

	T med = median(array[left],
					array[(left + right) / 2],
					array[right]);

	swap(array[med]);

	int pivot;
	int l_hold = left;
	int r_hold = right;

	pivot = array[left];

	while (left < right)
	{
		while (array[right] >= pivot && left < right)
			right--;

		if (left != right)
		{
			array[left] = array[right];
			left++;
		}

		while (array[left] <= pivot && left < right)
			left++;

		if (left != right)
		{
			array[right] = array[left];
			right--;
		}
	}

	array[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;

	if (left < pivot)
		qSort(array, left, pivot - 1);

	if (right > pivot)
		qSort(array, pivot + 1, right);
}

int main()
{
	int a[] = {55, 23, 9, 12, 67, 76, 13, 78, 12, 78, 4, 8, 2, 8, 3, 0, -1};

	for (int i = 0; i < 17; i++)
		cout << a[i] << ' ';

	cout << endl;
	qSort(a, 0, 16);

	for (int i = 0; i < 17; i++)
		cout << a[i] << ' ';

	return 0;
}
