#include "sort.h"
/**
* selection_sort - selection sort algorithm
* @array: pointer to array
* @size: size of array
* Return: nothing
*/
void selection_sort(int *array, size_t size)
{
size_t i = 0, j = 0, k = 0;
int smalest;

bool swap = false;

while (i < size)
{
	smalest = array[i];
	for (j = i; j < size; j++)
	{
		if (smalest > array[j])
		{
			smalest = array[j];
			swap = true;
			k = j;
		}
	}
	if (swap == true && k != 0)
	{
		while (k > i)
		{
			array[k] = array[k - 1];
			k--;
		}
		array[k] = smalest;
		print_array(array, size);
	}
	swap = false;
	i++;
}
}
