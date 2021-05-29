/**
 * Data structure classes
 *** Sort algorithm implementations ***
 *
 **/
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cb_utils.h"

int cb_sort(int (*cb_sor_algo)(void *list_old, void **list_new), void *list_old, void **list_new)
{
    cb_sor_algo(list_old, list_new);
}

int cb_bubble_sort(void *list_old, void **list_new)
{
    CB_NODE *old;
    CB_NODE *prev;
    CB_NODE *moving;
    CB_NODE *new;
    bool next;

    // Initialize variables
    prev = NULL;
    old = (CB_NODE *)list_old;
    new = (CB_NODE *)list_old;
    moving = old;

    // Main loop
    while(old != (CB_NODE *)NULL) 
    {
        moving = old->next;
        next = true;

        while(moving != (CB_NODE *)NULL && strcmp(old->value, moving->value) > 0)
        {
            cb_switch_node_next((void **)&new, prev, old, moving);
            prev = moving;
            moving = old->next;
            next = false;
        }

        // Move the cursor to the next record but keeps track of the previous record
        if(next == true)
        {
            prev = old;
            old  = old->next;
        }
        else
        {
            prev = NULL;
            old  = new;
        }
    }

    *list_new = new;
}
