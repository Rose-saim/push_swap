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
  
#include "push_swap.h"

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}

void quick_sort(int tab[], int first, int last)
{
    int pivot;
    int begin_first;
    int begin_end;
    
    if(first < last) 
    {
        pivot = first;
        begin_first = first;
        begin_end = last;
        while (begin_first < begin_end) 
        {
            while(tab[begin_first] <= tab[pivot] && begin_first < last)
                begin_first++;
            while(tab[begin_end] > tab[pivot])
                begin_end--;
            if(begin_first < begin_end) {
                swap(&tab[begin_first], &tab[begin_end]);
            }
        }
        swap(&tab[pivot], &tab[begin_end]);
        quick_sort(tab, first, begin_end - 1);
        quick_sort(tab, begin_end + 1, last);
    }
    return ;
}
