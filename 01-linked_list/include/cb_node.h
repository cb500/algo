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
    void *data;    // Can carry any value, determined by the user
    struct _CB_NODE *prev;  // Previous node in the list
    struct _CB_NODE *next;  // Next node in the list
};

typedef struct _CB_NODE CB_NODE;

// Node operations
CB_RETURN cb_node_initialize(CB_NODE **node);
CB_RETURN cb_node_initialize_data(CB_NODE **node, void *data);
void cb_node_destroy(CB_NODE **node);

// Node data manipulation
CB_RETURN cb_node_add_data(CB_NODE *node, const void *data, CB_RETURN (*cb_node_add_dta_callback)(CB_NODE *_node, const void *_data));
CB_RETURN cb_node_add_data_char(CB_NODE *node, const void *value);
void *cb_node_get_data(CB_NODE *node);

// Node data print
void cb_node_print(CB_NODE *node, void (*cb_print_nde)(CB_NODE *_node));
void cb_node_print_char(CB_NODE *node);


#endif // __CB_NODE_H