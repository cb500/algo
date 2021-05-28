/**
 * Data structure classes
 **/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define DEFAULT_FILE "../tests/sample.txt"

int main(int args, char *vargs[]) 
{
    int linePosition;
    int ret = 0;
    FILE *file = NULL;

    if(args > 1)
        file = fopen(vargs[1], "r");
    else
        file = fopen(DEFAULT_FILE, "r");

    if(file == NULL)
    {
        fprintf(stderr, "It wasn't possible to open the file!\n\n");
        return -1;
    }

    //
    CB_NODE *list = NULL;
    ret = cb_read_file_line(&cb_stack_push, file, (void **)&list, 0);
    printf("\n DONE with %d words read!! \n", ret);

    printf("-- OLD LIST ---------------------------------------------\n");
    cb_print(&cb_stack_print, (void *)list);

    printf("\n-- POP ELEMENTS FROM STACK ------------------------------\n");
    CB_NODE *node = cb_stack_pop((void **)&list);
    cb_stack_print(node);
    free(node);
    node = cb_stack_pop((void **)&list);
    cb_stack_print(node);
    free(node);

    printf("\n-- NEW LIST ---------------------------------------------\n");
    cb_print(&cb_stack_print, (void *)list);

    CB_NODE *list_new = NULL;
    cb_sort(&cb_stack_bubble_sort, list, (void *)&list_new);

    printf("\n-- NEW ORDERED LIST -------------------------------------\n");
    cb_print(&cb_stack_print, (void *)list_new);

    // Cleanup
    cb_node_destroy(list);

    return 0;
}