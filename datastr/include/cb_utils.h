#ifndef __CB_UTILS
#define __CB_UTILS

#include "cb_node.h"

typedef struct _CB_QUEUE
{
    CB_NODE *front;
    CB_NODE *rear;
    ssize_t count;
} CB_QUEUE;


// Util functions
CB_RETURN cb_read_file_line(CB_RETURN (*cb_add_node)(void **node, char *value), 
        CB_RETURN (*cb_init_struct)(void **cb_struct), FILE *file, void **list, u_int8_t sanitize);
void cb_print(void (*cb_print)(void *), void *root);
CB_RETURN cb_init_void (void **value);

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

// List
CB_RETURN cb_list_add_node(void **stack, char *value);
CB_RETURN cb_list_destroy(CB_NODE *list);

// Queue
CB_RETURN cb_queue_create(CB_QUEUE **queue);
void cb_queue_destroy(CB_QUEUE *queue);

CB_RETURN cb_queue_enqueue(CB_QUEUE *queue, CB_NODE *node);
CB_RETURN cb_queue_enqueue2(void **queue, char *value);
CB_NODE *cb_queue_dequeue(CB_QUEUE *queue);
CB_NODE *cb_queue_front(CB_QUEUE *queue);
CB_NODE *cb_queue_rear(CB_QUEUE *queue);
size_t cb_queue_count(CB_QUEUE *queue);

#endif // __CB_UTILS