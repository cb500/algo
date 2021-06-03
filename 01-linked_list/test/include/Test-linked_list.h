/**
 * node.h
 * Author: Charly Batista
 * Date: 2021-05-28
 **/

#ifndef __CB_TEST_LINKED_LIST_H
#define __CB_TEST_LINKED_LIST_H
#include <check.h>
#include <stdlib.h>

#include "cb_list.h"
#include "cb_node.h"

#define TEST_NODE_DATA "This is just a node"

Suite *cb_node_suite(void);
Suite *cb_list_init_suite(void);
Suite *cb_list_add_next_suite(void);
Suite *cb_list_del_next_suite(void);

#endif  //__CB_TEST_LINKED_LIST_H