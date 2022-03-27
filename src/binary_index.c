/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-pushswap-elouan.savy-camaret
** File description:
** binary_index
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int get_conversion_div(int nbr)
{
    int divisor = 2;

    while ((nbr / divisor) >= 2) {
        divisor *= 2;
    }
    return (divisor);
}

char *fill_res_to_size(char *result, int size)
{
    int current_size = my_strlen(result) - 1;
    result = my_revstr(result);

    while (current_size < size - 1) {
        current_size += 1;
        result[current_size] = '0';
    }
    return (my_revstr(result));
}

char *convert_binary(int size, int nbr)
{
    char *result = malloc(sizeof(char) * (size + 1));
    int divisor = get_conversion_div(nbr);
    int i = 0;

    while (nbr > 0 || divisor > 0) {
        result[i] = (nbr / divisor) + 48;
        nbr %= divisor;
        divisor /= 2;
        i += 1;
    }
    result[size] = '\0';
    result[i] = '\0';
    if (my_strlen(result) < size)
        result = fill_res_to_size(result, size);
    return (result);
}
