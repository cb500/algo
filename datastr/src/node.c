/**
 * Node implementation
 * Author: Charly Batista
 * Date: 2021-05-26
 **/

#include <stdlib.h>
#include <string.h>
#include "cb_utils.h"

CB_RETURN cb_node_initialize(void **newNode)
{
    CB_NODE *tmp;
    tmp = (CB_NODE *) malloc(sizeof(CB_NODE));
    if(tmp == (CB_NODE *)NULL)
        return CB_ERR_MEM_INIT;

    memset(tmp, 0, sizeof(tmp));
    tmp->next = NULL;
    tmp->prev = NULL;

    *newNode = tmp;

    return CB_OK;
}

void cb_node_destroy(void *node)
{
    if(node == (CB_NODE *)NULL)
        return;

    ((CB_NODE *)node)->next = NULL;
    ((CB_NODE *)node)->prev = NULL;
    if(((CB_NODE *)node)->value != (char *)NULL)
        free(((CB_NODE *)node)->value);
    free(node);
    node = NULL;
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


void cb_print_node(void *node)
{
    if(node != (CB_NODE *)NULL)
        printf("Node [%d]: %s\n", ((CB_NODE *)node)->id, ((CB_NODE *)node)->value);
}

CB_RETURN cb_node_add_value(CB_NODE *node, char *value)
{
    node->value = (char *)malloc(strlen(value));
    if(node->value == NULL)
        return CB_ERR_MEM_INIT;

    strcpy(node->value, value);
    return CB_OK;
}