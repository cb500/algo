/**
 * CB_NODE tests
 * Author: Charly Batista
 * Date: 2021-05-30
 **/

#include <check.h>
#include <stdlib.h>
#include "Test-linked_list.h"
#include "cb_node.h"

START_TEST(test_cb_node_lifetime)
{
    CB_NODE *node;
    int ret;

    // Initialize the node
    ret = cb_node_initialize(&node);

    // Check if the return is OK
    ck_assert_int_eq(ret, CB_OK);

    // Check if the node isn't NULL
    ck_assert_ptr_nonnull(node);

    // Cleanup
    cb_node_destroy(&node);

    // Check if the node is NULL
    ck_assert_ptr_null(node);
} END_TEST


START_TEST(test_cb_node_data) 
{
    CB_NODE *node1, *node2;
    int ret;
    char data[] = "Just data";

    // Initialize the node
    cb_node_initialize(&node1);
    cb_node_initialize(&node2);

    // Check the add_char funtion
    ret = cb_node_add_data_char(node1, (void *)data);
    ck_assert_int_eq(ret, CB_OK);
    ck_assert_str_eq(node1->data, "Just data");

    // Check the generic add_data function using the add_char function as callback
    ret = cb_node_add_data(node2, (void *) data, &cb_node_add_data_char);
    ck_assert_int_eq(ret, CB_OK);
    ck_assert_str_eq(node2->data, "Just data");

    // Compare the two nodes and they shall have the same data
    ck_assert_str_eq(node1->data, node2->data);

    // Check the generic get_data function that just returns the void value
    ck_assert_str_eq(cb_node_get_data(node1), "Just data");

    // Cleanup
    cb_node_destroy(&node1);
    cb_node_destroy(&node2);
} END_TEST

Suite *cb_node_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_node");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_cb_node_lifetime);
    tcase_add_test(tc_core, test_cb_node_data);

    suite_add_tcase(s, tc_core);

    return s;
}
