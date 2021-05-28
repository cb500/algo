#ifndef __TREE_NODE_H
#define __TREE_NODE_H

#include <stdio.h>
#include <sys/types.h>

struct _CB_NODE
{
    u_int32_t id;
    u_int32_t origPosition;
    void *value;
    struct _CB_NODE *prev;
    struct _CB_NODE *next;
};

typedef struct _CB_NODE CB_NODE;

struct _CB_QUEUE
{
    CB_NODE *front;
    CB_NODE *rear;
    ssize_t count;
};

typedef enum {
    OK              = 0,
    ERROR_MEM_INIT  = -1,
    ERROR_NULL      = -2,
    ERROR_GENERIC   = -99
} CB_RETURN;

// Node operations
CB_RETURN cb_node_initialize(void **newNode);
void cb_node_destroy(void *node);
void cb_print_node(void *node);


// Util functions
CB_RETURN cb_read_file_line(CB_RETURN (*cb_add_node)(void **node, char *value), FILE *file, void **list, u_int8_t sanitize);
void cb_print(void (*cb_print)(void *), void *root);


//// Sorting
int cb_sort(int (*cb_sor_algo)(void *list_old, void **list_new), void *list_old, void **list_new);
int cb_bubble_sort(void *list_old, void **list_new);
int cb_stack_bubble_sort(void *list_old, void **list_new);
void cb_switch_node(void (*cb_switch_algo)(void **root, void *prev, void *nd1, void *nd2), void **root, void *prev, void *nd1, void *nd2);
void cb_switch_node_prev(void **root, void *prev, void *node1, void *node2);
void cb_switch_node_next(void **root, void *prev, void *node1, void *node2);

// Stack
CB_RETURN cb_stack_push(void **stack, char *value);
void *cb_stack_pop(void **stack);
void cb_stack_print(void *stack);

#endif // __TREE_NODE_H