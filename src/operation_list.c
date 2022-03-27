/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-pushswap-elouan.savy-camaret
** File description:
** operation_list
*/

#include "my.h"
#include "push_swap.h"

op_t *put_in_op_list(op_t *list, char *op)
{
    op_t *element;

    element = malloc(sizeof(op_t));
    element->op = op;
    element->next = list;
    if (list != NULL)
        list->prev = element;
    element->prev = NULL;
    list = element;
    return (list);
}

void print_list(op_t *list)
{
    while (list->next != NULL)
        list = list->next;
    while (list->prev != NULL) {
        my_printf("%s ", list->op);
        list = list->prev;
    }
    my_printf("%s\n", list->op);
}
