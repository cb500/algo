/**
 * node.h
 * Author: Charly Batista
 * Date: 2021-05-28
 **/

#ifndef __CB_NODE_H
#define __CB_NODE_H

#include <stdio.h>
#include <sys/types.h>
#include "cb_types.h"

struct _CB_NODE
{
    u_int32_t id;   // It is the original position in the list when the node was created
    u_int32_t pos;  // Current position in the list
    void *value;    // Can carry any value, determined by the user
    struct _CB_NODE *prev;  // Previous node in the list
    struct _CB_NODE *next;  // Next node in the list
};

typedef struct _CB_NODE CB_NODE;

// Node operations
CB_RETURN cb_node_initialize(CB_NODE **node);
void cb_node_destroy(CB_NODE **node);
void cb_print_node(CB_NODE *node);
CB_RETURN cb_node_add_data(CB_NODE *node, char *value);
void *cb_node_get_data(CB_NODE *node, void *(*cb_get_data)(CB_NODE *node));

#endif // __CB_NODE_H