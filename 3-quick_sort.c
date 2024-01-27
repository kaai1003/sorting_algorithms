#include "sort.h"
/**
* quick_sort - quick sort algorithm
* @array: pointer to array of int
* @size: size of array
* Return: nothing
*/
void quick_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0;
int smalest;

bool swap = false;

while (i < size)
{
	smalest = array[i];
	swap = false;
	for (j = i; j < size; j++)
	{
		if (smalest > array[j])
		{
			smalest = array[j];
			swap = true;
			k = j;
		}
	}
	if (swap == true)
	{
		array[k] = array[i];
		array[i] = smalest;
		print_array(array, size);
	}
	i++;
}
}
