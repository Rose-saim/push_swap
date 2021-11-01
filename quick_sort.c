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
