/**
 * Node implementation
 * Author: Charly Batista
 * Date: 2021-05-26
 **/

#include <stdlib.h>
#include <string.h>
#include "cb_node.h"

CB_RETURN cb_node_initialize(CB_NODE **node)
{
    CB_NODE *tmp;
    tmp = (CB_NODE *) malloc(sizeof(CB_NODE));
    if(tmp == (CB_NODE *)NULL)
        return CB_ERR_MEM_INIT;

    memset(tmp, 0, sizeof(CB_NODE));
    tmp->next = NULL;
    tmp->prev = NULL;

    *node = tmp;

    return CB_OK;
}

void cb_node_destroy(CB_NODE **node)
{
    CB_NODE *tmp;

    if(node == (CB_NODE **)NULL ||
        *node == (CB_NODE *)NULL)
        return;

    tmp = *node;
    tmp->next = NULL;
    tmp->prev = NULL;
    if(tmp->data != (char *)NULL)
        free(tmp->data);

    free(tmp);
    tmp = NULL;
    *node = tmp;
}

// Data manipulation functions
CB_RETURN cb_node_add_data(CB_NODE *node, void *data, CB_RETURN (*cb_node_add_dta_callback)(CB_NODE *_node, void *_data))
{
    return cb_node_add_dta_callback(node, data);
}


CB_RETURN cb_node_add_data_char(CB_NODE *node, void *value)
{
    node->data = (char *)malloc(strlen((char *)value));
    if(node->data == NULL)
        return CB_ERR_MEM_INIT;

    strcpy(node->data, (char *)value);
    return CB_OK;
}

void *cb_node_get_data(CB_NODE *node)
{
    if(node == (CB_NODE *)NULL)
        return NULL;
    return node->data;
}

// Printing functions
void cb_node_print(CB_NODE *node, void (*cb_print_nde)(CB_NODE *_node))
{
    cb_print_nde(node);
}

void cb_node_print_char(CB_NODE *node)
{
    if(node != (CB_NODE *)NULL)
        printf("Node [%d]: %s\n", ((CB_NODE *)node)->id, (char *)((CB_NODE *)node)->data);
}


void cb_switch_node(void (*cb_switch_algo)(void **root, void *prev, void *nd1, void *nd2),
    void **root,
    void *prev,
    void *nd1,
    void *nd2)
{
    cb_switch_algo(root, prev, nd1, nd2);
}

void cb_switch_node_prev(void **root, void *prev, void *nd1, void *nd2)
{
    CB_NODE *tmp = ((CB_NODE *)nd2)->prev;

    // Check if the previous value is NULL.
    // It will happen if this is the 1st node to be moved
    if(prev != (CB_NODE *)NULL)
        ((CB_NODE *)prev)->prev = nd2;
    else
        *root = nd2;

    ((CB_NODE *)nd2)->prev = nd1;
    ((CB_NODE *)nd1)->prev = tmp;
}

void cb_switch_node_next(void **root, void *prev, void *nd1, void *nd2)
{
    CB_NODE *tmp = ((CB_NODE *)nd2)->next;

    // Check if the previous value is NULL.
    // It will happen if this is the 1st node to be moved
    if(prev != (CB_NODE *)NULL)
        ((CB_NODE *)prev)->next = nd2;
    else
        *root = nd2;

    ((CB_NODE *)nd2)->next = nd1;
    ((CB_NODE *)nd1)->next = tmp;
}
