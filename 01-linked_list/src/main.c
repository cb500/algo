#include <stdio.h>
#include "cb_list.h"
#include "cb_node.h"

#define TEST_NODE_DATA "This is just a node"
CB_LIST *tlist;
CB_RETURN tret;
CB_NODE *tnode;
char *tdata;

// Local variable
CB_NODE *tnode_arr[5];

void setup(void)
{
    char tmp_data[30];
    tlist = NULL;
    tnode = NULL;

    // Initialize LIST object
    cb_list_init(&tlist, &cb_list_destroy);

    // Create the list of 10 nodes
    for(int i=0; i<30; i++)
    {
        sprintf(tmp_data, "%s %d", TEST_NODE_DATA, i);
        cb_list_ins_next(tlist, NULL, tmp_data, &cb_node_initialize_data);

        switch (i)
        //29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0
        //0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
        {
        case 4: // Position number 25
            tnode_arr[0] = tlist->head;
            break;
        case 13: // Position number 16
            tnode_arr[1] = tlist->head;
            break;
        case 19: // Position number 10
            tnode_arr[2] = tlist->head;
            break;
        case 23: // Position number 6
            tnode_arr[3] = tlist->head;
            break;
        case 28: // Position number 1
            tnode_arr[4] = tlist->head;
            break;
        default:
            break;
        }
        tnode = NULL;
    }
}

int main()
{
    setup();
    tnode = cb_list_find_by_pos(tlist, 4);
    cb_list_traverse(tlist);

    return 0;
}