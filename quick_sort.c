#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	save;

	save = *a;
	*a = *b;
	*b = save;
}

int	partition(int array[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	j = low;
	i = low - 1;
	printf("pivot|%d\n", pivot);
	while (j < high)
	{
		if (array[j] < pivot)
		{
			++i;
			swap(&array[i], &array[j]);;
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	printf("%d|%d\n", array[i], i + 1);
	return (i + 1);
}


void	quicksort(int arr[], int low, int high)
{
	int	pi;

	pi = partition(arr, low, high);
	printf("pi%d\n", pi);
	if (low < high)
	{
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

  
// Driver Code
int main() 
{ 
	int	i = 0;
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quicksort(arr, 0, n - 1);
	while (i < n)
	{
		printf("%d|", arr[i]);
		i++;
	}
    return 0; 
} 
  