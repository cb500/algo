/**
 * Stack implementation
 * Author: Charly Batista
 * Date: 2021-05-26
 **/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

CB_RETURN cb_stack_push(void **stack, char *value)
{
    CB_RETURN ret = OK;
    CB_NODE *new;
    if(ret = cb_node_initialize((void **)&new))
        return ret;

    new->value = (char *)malloc(strlen(value));
    if(new->value == NULL)
    {
        cb_node_destroy(new);
        return ERROR_MEM_INIT;
    }

    strcpy(new->value, value);
    if(*stack != (CB_NODE *)NULL)
    {
        new->id = ((CB_NODE *)(*stack))->id + 1;
        new->origPosition = ((CB_NODE *)(*stack))->origPosition + 1;
        new->prev = *stack;
    }

    *stack = new;

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