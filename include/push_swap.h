/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-pushswap-elouan.savy-camaret
** File description:
** push_swap
*/

#ifndef PUSH_SWAP_H_
    #define PUSH_SWAP_H_

typedef struct nb_list {
    int nbr;
    char *index;
    struct nb_list *next;
} nb_t;

typedef struct intructions {
    char *op;
    void (*func)(nb_t **la, nb_t **lb);
} instruc_t;

typedef struct operation {
    char *op;
    struct operation *next;
    struct operation *prev;
} op_t;

typedef struct radix_strcut {
    nb_t **la;
    nb_t **lb;
    op_t **op;
} radix_t;

void rrotate_a(nb_t **l_a, nb_t **l_b);
void rotate_a(nb_t **l_a, nb_t **l_b);
void push(nb_t **src, nb_t **dest);
nb_t *put_in_nb_list(nb_t *list, int nbr);
void print_list(op_t *list);
nb_t *create_list(int argc, char **argv);
char *convert_binary(int size, int nbr);
nb_t **list_to_arr(nb_t *list, int size);
void index_list(nb_t **arr, int size, int length);
int get_conversion_div(int nbr);
int get_digits_size(int size);
op_t *put_in_op_list(op_t *list, char *op);
void manage_list_op(nb_t **la, nb_t **lb, char *op, op_t **op_list);
void radix_handler(nb_t *la, int digits_size, int list_size);
int is_list_sorted(nb_t *list, int size);
int pushswap_handler(int argc, char **argv);
#endif /* !PUSH_SWAP_H_ */
