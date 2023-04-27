#include <stdlib.h>
#include "pod.h"

/**
 * _calloc - allocates memory for an array and initializes it to 0
 * @num_elements: number of elements to allocate memory for
 * @element_size: size of each element in bytes
 * Return: pointer to the allocated memory or NULL if allocation fails
 */
void *_calloc(unsigned int num_elements, unsigned int element_size)
{
	void *allocated_memory = NULL;
	unsigned int i;

	if (num_elements == 0 || element_size == 0)
	{
		return (NULL);
	}

	allocated_memory = malloc(num_elements * element_size);

	if (allocated_memory == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < (num_elements * element_size); i++)
	{
		*((char *)(allocated_memory) + i) = 0;
	}

	return (allocated_memory);
}
