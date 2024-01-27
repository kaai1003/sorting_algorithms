#include "sort.h"
/**
* selection_sort - selection sort algorithm
* @array: pointer to array
* @size: size of array
* Return: nothing
*/
void selection_sort(int *array, size_t size)
{
size_t i = 0, j = 0, k;
int smalest;

k = size - 1;
while (i < size)
{
	smalest = array[i];
	j = i + 1;
	while (j < size)
	{
		if (smalest > array[j])
		{
			smalest = array[j];
			k = j;
		}
		j++;
	}
	if (smalest != array[i])
	{
		array[k] = array[i];
		array[i] = smalest;
		print_array(array, size);
	}
	i++;
}
}
