/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-pushswap-elouan.savy-camaret
** File description:
** tests_push_swap
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "push_swap.h"

void print_nbr_list(nb_t *list)
{
    while (list != NULL) {
        my_printf("%d, ", list->nbr);
        list = list->next;
    }
    my_printf("\n");
}

void redirect_all_std ( void )
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(rotate_a, ra, .init = redirect_all_std)
{
    char *nbr[] = {"binary", "1", "2", "3", "4", "5"};
    nb_t *la = create_list(6, nbr);
    rotate_a(&la, NULL);
    print_nbr_list(la);
    cr_assert_stdout_eq_str ("2, 3, 4, 5, 1, \n");
}

Test(rrotate_a, rra, .init = redirect_all_std)
{
    char *nbr[] = {"binary", "1", "2", "3", "4", "5"};
    nb_t *la = create_list(6, nbr);
    rrotate_a(&la, NULL);
    print_nbr_list(la);
    cr_assert_stdout_eq_str ("5, 1, 2, 3, 4, \n");
}

Test(push, pb, .init = redirect_all_std)
{
    char *nbr[] = {"binary", "1", "2", "3", "4", "5"};
    nb_t *la = create_list(6, nbr);
    nb_t *lb = NULL;
    push(&la, &lb);
    print_nbr_list(la);
    print_nbr_list(lb);
    cr_assert_stdout_eq_str ("2, 3, 4, 5, \n1, \n");
}

Test(push, invalid_pb, .init = redirect_all_std)
{
    char *nbr[] = {"binary", "1", "2", "3", "4", "5"};
    nb_t *la = create_list(6, nbr);
    nb_t *lb = NULL;
    push(&lb, &la);
    print_nbr_list(la);
    print_nbr_list(lb);
    cr_assert_stdout_eq_str ("1, 2, 3, 4, 5, \n\n");
}

Test(convert_binary, conversion, .init = redirect_all_std)
{
    char *str = convert_binary(17, 27683);
    my_printf("%s\n", str);
    cr_assert_stdout_eq_str ("00110110000100011\n");
}

Test(get_digits_size, calc_size, .init = redirect_all_std)
{
    int size = get_digits_size(38556);
    cr_assert_eq (size, 16);
}

Test(is_list_sorted, list_sorted)
{
    char *nbr[] = {"binary", "-1", "2", "3", "4", "5"};
    nb_t *la = create_list(6, nbr);
    cr_assert_eq (is_list_sorted(la, 5), 1);
}

Test(is_list_sorted, list_not_sorted)
{
    char *nbr[] = {"binary", "1", "2", "-3", "4", "5"};
    nb_t *la = create_list(6, nbr);
    cr_assert_eq (is_list_sorted(la, 5), 0);
}

Test(integration, unsorted_list, .init = redirect_all_std)
{
    char *argv[] = {"binary", "29", "-5445", "-53", "114", "34", "0", "1", "64", "6527", "856", "7543", "5324", "4", "5", "6"};
    int argc = 16;
    pushswap_handler(argc, argv);
    cr_assert_stdout_eq_str ("pb ra pb ra ra ra pb pb pb pb ra ra ra pb ra pa pa pa pa pa pa pa pb ra pb ra ra pb ra pb ra pb ra ra pb pb ra pa pa pa pa pa pa pa pb ra ra pb pb ra ra pb pb ra ra pb pb ra ra pa pa pa pa pa pa pa ra pb ra pb ra ra pb pb ra ra pb ra pb ra pb pa pa pa pa pa pa pa\n");
}

Test(integration_2, sorted_list, .init = redirect_all_std)
{
    char *argv[] = {"binary", "1", "2", "3", "4", "5"};
    int argc = 6;
    pushswap_handler(argc, argv);
    cr_assert_stdout_eq_str ("\n");
}
