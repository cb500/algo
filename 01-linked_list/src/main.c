#include <stdio.h>
#include "cb_node.h"

int main()
{
    CB_NODE *node;
    int ret;

    // Initialize the node
    ret = cb_node_initialize(&node);
    printf("The function has returned %d\n", ret);
    cb_node_destroy(&node);
    printf("Done with the binary!!\n");

    return 0;
}