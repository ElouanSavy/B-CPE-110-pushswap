/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-pushswap-elouan.savy-camaret
** File description:
** manage_list
*/

#include <stdlib.h>

#include "push_swap.h"
#include "my.h"

int is_list_sorted(nb_t *list, int size)
{
    int i = 0;

    while (list->next != NULL && list->nbr < list->next->nbr) {
        i += 1;
        list = list->next;
    }
    return (i == (size - 1));
}

nb_t *put_in_nb_list(nb_t *list, int nbr)
{
    nb_t *element = malloc(sizeof(nb_t));

    element->nbr = nbr;
    element->next = list;
    list = element;
    return (list);
}

nb_t *create_list(int argc, char **argv)
{
    nb_t *list = NULL;

    for (int i = argc - 1; i > 0; i -= 1) {
        list = put_in_nb_list(list, my_getnbr(argv[i]));
    }
    return (list);
}

int pushswap_handler(int argc, char **argv)
{
    nb_t *la = create_list(argc, argv);
    nb_t **arr;
    int length = get_digits_size(argc - 2);

    if (is_list_sorted(la, (argc - 1))) {
        my_printf("\n");
        return (0);
    }
    arr = list_to_arr(la, argc);
    index_list(arr, (argc - 1), length);
    radix_handler(la, length, (argc - 1));
    return (0);
}
