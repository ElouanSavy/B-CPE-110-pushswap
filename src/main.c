/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-pushswap-elouan.savy-camaret
** File description:
** main
*/

#include "my.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        return (84);
    } else if (argc == 2) {
        my_printf("\n");
        return (0);
    }
    return (pushswap_handler(argc, argv));
}
