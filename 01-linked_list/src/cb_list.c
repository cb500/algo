/**
 * List implementation
 * Author: Charly Batista
 * Date: 2021-05-31
 **/

#include <stdlib.h>
#include <string.h>
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

CB_RETURN cb_list_ins_next(CB_LIST *list, CB_NODE *element, const void *data, CB_RETURN (*cb_node_initialize_callback)(CB_NODE **nde, const void *dta))
{
    CB_RETURN ret = CB_OK;
    CB_NODE *node;
    if(list == (CB_LIST *)NULL)
        return CB_ERR_NULL;

    // Create and  populate the NODE
    node = element;

    // Check if the callback function is NULL and if NULL uses the default callback
    if(cb_node_initialize_callback == NULL)
        cb_node_initialize_callback = cb_node_initialize_data;

    // Initialize the node populating with the given DATA
    cb_node_initialize_callback(&node, data);
    node->next = list->head;

    // Update the list
    list->size++;
    list->head = node;
    if(list->size == 1)
        list->tail = node;

    return ret;
}

CB_RETURN cb_list_del_next(CB_LIST *list, CB_NODE *criteria, CB_NODE **removed)
{
    CB_NODE *node;
    CB_NODE *tmp;
    if(list == (CB_LIST *)NULL)
        return CB_ERR_NULL;

    if(removed == NULL)
        return CB_ERR_NULL;

    node = NULL;
    if(criteria != list->tail)
    {
        if(criteria == NULL)
        {
            node = list->head;
            list->head = node->next;
        }
        else
        {
            tmp = list->head;
            while(tmp != NULL)
            {
                if(tmp == criteria)
                {
                    node = tmp->next;
                    tmp->next = node->next;
                    break;
                }
                tmp = tmp->next;
            }
        }
    }

    *removed = node;
    return CB_OK;
}

CB_NODE *cb_list_find(const CB_LIST *list, const void *params, CB_NODE *(*cb_list_find_callback)(const CB_LIST *lst, const void *prams))
{
    return cb_list_find_callback(list, params);
}

CB_NODE *cb_list_find_by_data(const CB_LIST *list, const void *params)
{
    CB_NODE *node;
    CB_NODE *tmp;

    tmp = list->head;
    node = NULL;
    while (tmp != (CB_NODE *)NULL)
    {
        if(!strcmp(tmp->data, params))
        {
            node = tmp;
            break;
        }
        tmp = tmp->next;
    }

    return node;
}

CB_NODE *cb_list_find_by_pos(const CB_LIST *list, const ssize_t pos)
{
    CB_NODE *node;
    CB_NODE *tmp;
    ssize_t counter;

    tmp = list->head;
    counter = 0;
    node = NULL;
    while (tmp != (CB_NODE *)NULL)
    {
        if(pos == counter++)
        {
            node = tmp;
            break;
        }
        tmp = tmp->next;
    }

    return node;
}
/*
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

void cb_list_traverse(CB_LIST *list)
{

}
*/