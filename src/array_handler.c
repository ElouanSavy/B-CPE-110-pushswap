/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-pushswap-elouan.savy-camaret
** File description:
** array_handler
*/

#include "my.h"
#include "push_swap.h"

nb_t **list_to_arr(nb_t *list, int size)
{
    nb_t **arr = malloc(sizeof(nb_t *) * (size + 1));
    int i = 0;

    arr[size] = NULL;
    while (list != NULL) {
        arr[i] = list;
        i += 1;
        list = list->next;
    }
    return (arr);
}

void swap_array_elem(nb_t **array, int index1, int index2)
{
    nb_t *temp;

    temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void quick_sort(nb_t **array, int first, int last)
{
    int i;
    int j;
    int pivot;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (array[i]->nbr <= array[pivot]->nbr && i < last)
                i += 1;
            while (array[j]->nbr > array[pivot]->nbr)
                j -= 1;
            if (i < j)
                swap_array_elem(array, i, j);
        }
        swap_array_elem(array, pivot, j);
        quick_sort(array, first, j - 1);
        quick_sort(array, j + 1, last);
    }
}

int get_digits_size(int size)
{
    int nbr = get_conversion_div(size);
    int counter = 0;

    while (nbr > 0) {
        counter += 1;
        nbr /= 2;
    }
    return (counter);
}

void index_list(nb_t **arr, int size, int length)
{
    quick_sort(arr, 0, size - 1);
    for (int i = 1; i <= size; i++) {
        arr[i - 1]->index = convert_binary(length, i);
    }
}
