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
    tmp->data = NULL;
    tmp->next = NULL;
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
    if(tmp->data != (char *)NULL)
        free(tmp->data);

    free(tmp);
    tmp = NULL;
    *node = tmp;
}

CB_RETURN cb_node_initialize_data(CB_NODE **node, const void *data)
{
    CB_RETURN ret;
    ret = cb_node_initialize(node);
    if(ret)
        return ret;

    ret = cb_node_add_data_char(*node, data);
    return ret;
}

// Data manipulation functions
CB_RETURN cb_node_add_data(CB_NODE *node, const void *data, CB_RETURN (*cb_node_add_dta_callback)(CB_NODE *_node, const void *_data))
{
    return cb_node_add_dta_callback(node, data);
}


CB_RETURN cb_node_add_data_char(CB_NODE *node, const void *value)
{
    if(node == (CB_NODE *) NULL)
        return CB_ERR_NULL;

    const char *tmp = (char *)value;
    node->data = (char *)malloc(strlen(tmp) + 1);
    if(node->data == NULL)
        return CB_ERR_MEM_INIT;

    strcpy(node->data, tmp);
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
