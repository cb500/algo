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
    u_int32_t id;
    u_int32_t origPosition;
    void *data;
    struct _CB_NODE *prev;
    struct _CB_NODE *next;
};

typedef struct _CB_NODE CB_NODE;

// Node operations
CB_RETURN cb_node_initialize(void **newNode);
void cb_node_destroy(void *node);
void cb_print_node(void *node);
CB_RETURN cb_node_add_value(CB_NODE *node, char *value);

#endif // __CB_NODE_H