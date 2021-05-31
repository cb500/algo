/**
 * node.h
 * Author: Charly Batista
 * Date: 2021-05-28
 **/

#ifndef __CB_LIST_H
#define __CB_LIST_H

#include <sys/types.h>
#include "cb_node.h"

typedef struct _CB_LIST CB_LIST;
struct _CB_LIST
{
    CB_NODE *head;
    CB_NODE *tail;
    u_int32_t size;
    void (*cb_list_destructor)(CB_LIST **list);
};

CB_RETURN cb_list_init(CB_LIST **list, void (*cb_list_destructor_callback)(CB_LIST **list));
void cb_list_destroy(CB_LIST **list);
CB_RETURN cb_list_ins_next(CB_LIST *list, CB_NODE *element, const void *data, CB_RETURN (*cb_node_initialize_callback)(CB_NODE **nde, void *dta));

CB_RETURN cb_list_del_next(CB_LIST *list, CB_NODE *element, void **data);
CB_RETURN cb_list_get_size(const CB_LIST *list);
CB_NODE *cb_list_get_head(const CB_LIST *list);
CB_NODE *cb_list_get_tail(const CB_LIST *list);
CB_NODE *cb_list_get_next(const CB_NODE *element);
CB_RETURN cb_list_is_head(const CB_NODE *element);
CB_RETURN cb_list_is_tail(const CB_NODE *element);

#endif  // __CB_LIST_H