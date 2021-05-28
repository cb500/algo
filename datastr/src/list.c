/**
 * Stack implementation
 * Author: Charly Batista
 * Date: 2021-05-26
 **/

#include <stdlib.h>
#include <string.h>
#include "utils.h"

CB_RETURN cb_list_add_node(void **stack, char *value)
{
    // Create and initialize a new node
    CB_RETURN ret = OK;
    CB_NODE *node;
    if(ret = cb_node_initialize((void **)&node))
        return ret;

    node->value = (char *)malloc(strlen(value));
    if(node->value == NULL)
    {
        cb_node_destroy(node);
        return ERROR_MEM_INIT;
    }

    // Populate the node with the acquired values
    strcpy(node->value, value);
    if(*stack != (CB_NODE *)NULL)
    {
        node->id = ((CB_NODE *)(*stack))->id + 1;
        node->origPosition = ((CB_NODE *)(*stack))->origPosition + 1;
        node->next = *stack;
    }

    *stack = node;

    return ret;

}