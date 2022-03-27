/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-pushswap-elouan.savy-camaret
** File description:
** list_op
*/

#include <stdlib.h>

#include "push_swap.h"
#include "my.h"

const instruc_t inst[] = {
    {"pa", &push},
    {"pb", &push},
    {"ra", &rotate_a},
    {"rra", &rrotate_a}
};

void manage_list_op(nb_t **la, nb_t **lb, char *op, op_t **op_list)
{
    for (int i = 0; i < 4; i += 1) {
        if (!my_strcmp(op, inst[i].op)) {
            inst[i].func(la, lb);
            *op_list = put_in_op_list(*op_list, op);
        }
    }
}

void push(nb_t **src, nb_t **dest)
{
    nb_t *tmp = *src;

    if (*src == NULL)
        return;
    if (*dest == NULL) {
        (*src) = (*src)->next;
        tmp->next = NULL;
        (*dest) = tmp;
    } else {
        (*src) = (*src)->next;
        tmp->next = (*dest);
        (*dest) = tmp;
    }
}

void rrotate_a(nb_t **l_a,__attribute__ ((unused)) nb_t **l_b)
{
    nb_t *f_elements = (*l_a);
    nb_t *new_first = NULL;

    while ((*l_a)->next->next != NULL)
        (*l_a) = (*l_a)->next;
    new_first = (*l_a)->next;
    new_first->next = f_elements;
    (*l_a)->next = NULL;
    (*l_a) = new_first;
}

void rotate_a(nb_t **l_a,__attribute__ ((unused)) nb_t **l_b)
{
    nb_t *f_elements = (*l_a);
    nb_t *new_first = (*l_a)->next;

    while ((*l_a)->next != NULL)
        (*l_a) = (*l_a)->next;
    (*l_a)->next = f_elements;
    f_elements->next = NULL;
    (*l_a) = new_first;
}
