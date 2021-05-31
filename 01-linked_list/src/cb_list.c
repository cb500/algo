/**
 * Node implementation
 * Author: Charly Batista
 * Date: 2021-05-31
 **/

#include <stdlib.h>
#include "cb_node.h"
#include "cb_list.h"

CB_RETURN cb_list_init(CB_LIST **list, void (*cb_list_destructor_callback)(CB_LIST **list))
{
    CB_LIST *nlist;
    nlist = (CB_LIST *)malloc(sizeof(CB_LIST));
    if(nlist == (CB_LIST *)NULL)
        return CB_ERR_MEM_INIT;

    nlist->size = 0;
    nlist->head = NULL;
    nlist->tail = NULL;
    nlist->cb_list_destructor = cb_list_destructor_callback;
    *list = nlist;

    return CB_OK;
}

void cb_list_destroy(CB_LIST **list)
{
    CB_NODE *node;
    CB_LIST *tmp;
    if(list == (CB_LIST **)NULL ||
        *list == (CB_LIST *)NULL)
        return;

    tmp = *list;
    while((node = tmp->head) != (CB_NODE *)NULL)
    {
        tmp->head = tmp->head->next;
        cb_node_destroy(&node);
    }

    free(tmp);
    tmp = NULL;
    *list = tmp;
}

CB_RETURN cb_list_ins_next(CB_LIST *list, CB_NODE *element, const void *data, CB_RETURN (*cb_node_initialize)(CB_NODE **nde, void *dta))
{
    return CB_ERR_GENERIC;
}
/*
CB_RETURN cb_list_del_next(CB_LIST *list, CB_NODE *element, void **data)
{
    return CB_ERR_GENERIC;
}

CB_RETURN cb_list_get_size(const CB_LIST *list)
{
    return CB_ERR_GENERIC;
}

CB_NODE *cb_list_get_head(const CB_LIST *list)
{
    return NULL;
}

CB_NODE *cb_list_get_tail(const CB_LIST *list)
{
    return NULL;
}

CB_NODE *cb_list_get_next(const CB_NODE *element)
{
    return NULL;
}

CB_RETURN cb_list_is_head(const CB_NODE *element)
{
    return CB_ERR_GENERIC;
}

CB_RETURN cb_list_is_tail(const CB_NODE *element)
{
    return CB_ERR_GENERIC;
}
*/