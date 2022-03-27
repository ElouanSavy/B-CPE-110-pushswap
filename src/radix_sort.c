/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-pushswap-elouan.savy-camaret
** File description:
** radix_sort
*/

#include "my.h"
#include "push_swap.h"

void compare_digits(radix_t *radix, int size, int digits)
{
    int i = 0;

    while (i < size && (*radix->la) != NULL) {
        if ((*radix->la)->index[digits] == '0')
            manage_list_op(radix->la, radix->lb, "pb", radix->op);
        else
            manage_list_op(radix->la, radix->lb, "ra", radix->op);
        i += 1;
    }
}

void connect_list(radix_t *radix)
{
    while ((*radix->lb) != NULL) {
        manage_list_op(radix->lb, radix->la, "pa", radix->op);
    }
}

void radix_handler(nb_t *la, int digits_size, int list_size)
{
    nb_t *lb = NULL;
    op_t *op = NULL;
    int i = digits_size - 1;
    radix_t radix = {&la, &lb, &op};

    while (i >= 0) {
        compare_digits(&radix, list_size, i);
        connect_list(&radix);
        i -= 1;
    }
    print_list(op);
}
