/**
 * Stack implementation
 * Author: Charly Batista
 * Date: 2021-05-26
 **/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cb_utils.h"

CB_RETURN cb_init_stack (void **stack)
{ 
    return CB_OK;
}

CB_RETURN cb_stack_push(void **stack, char *value)
{
    CB_RETURN ret = CB_OK;
    CB_NODE *node;
    if(ret = cb_node_initialize((void **)&node))
        return ret;

    if(ret = cb_node_add_value(node, value))
    {
        cb_node_destroy(node);
        return CB_ERR_MEM_INIT;
    }

    if(*stack != (CB_NODE *)NULL)
    {
        node->id = ((CB_NODE *)(*stack))->id + 1;
        node->origPosition = ((CB_NODE *)(*stack))->origPosition + 1;
        node->prev = *stack;
    }

    *stack = node;

    return ret;
}

void *cb_stack_pop(void **stack)
{
    CB_NODE *node;
    node = (CB_NODE *)(*stack);
    *stack = ((CB_NODE *)(*stack))->prev;
    node->prev = NULL;

    return node;
}

void cb_stack_print(void *stack)
{
    CB_NODE *node;
    node = (CB_NODE *)stack;
    while(node != (CB_NODE *)NULL)
    {
        cb_print_node(node);
        node = node->prev;
    }
}

int cb_stack_bubble_sort(void *list_old, void **list_new)
{
    CB_NODE *old;
    CB_NODE *prev;
    CB_NODE *moving;
    CB_NODE *new;
    bool has_prev;

    // Initialize variables
    prev = NULL;
    old = (CB_NODE *)list_old;
    new = (CB_NODE *)list_old;
    moving = old;

    // Main loop
    while(old != (CB_NODE *)NULL) 
    {
        moving = old->prev;
        has_prev = true;

        while(moving != (CB_NODE *)NULL && strcmp(old->value, moving->value) > 0)
        {
            cb_switch_node_prev((void **)&new, prev, old, moving);
            prev = moving;
            moving = old->prev;
            has_prev = false;
        }

        // Move the cursor to the prev record but keeps track of the previous record
        if(has_prev == true)
        {
            prev = old;
            old  = old->prev;
        }
        else
        {
            prev = NULL;
            old  = new;
        }
    }

    *list_new = new;
}