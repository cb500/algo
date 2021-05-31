/**
 * CB_LIST tests
 * Author: Charly Batista
 * Date: 2021-05-31
 **/

#include <check.h>
#include <stdlib.h>
#include "Test-linked_list.h"
#include "cb_list.h"
#include "cb_node.h"

START_TEST(test_cb_list_initialize)
{
    CB_LIST *list;
    int ret;

    // Initialize the node
    ret = cb_list_init(&list, &cb_list_destroy);

    // Check if the return is OK
    ck_assert_int_eq(ret, CB_OK);

    // Check if the node isn't NULL
    ck_assert_ptr_nonnull(list);

    // Cleanup
    free(list);
} END_TEST


START_TEST(test_cb_list_empty_destroy)
{
    CB_LIST *list;

    // Initialize the node
    cb_list_init(&list, &cb_list_destroy);

    // Destroy the node
    cb_list_destroy(&list);

    // Check if the node is really NULL
    ck_assert_ptr_null(list);

} END_TEST

START_TEST(test_cb_list_empty_destroy_callback)
{
    CB_LIST *list;

    // Initialize the node
    cb_list_init(&list, &cb_list_destroy);

    // Destroy the node
    list->cb_list_destructor(&list);

    // Check if the node is really NULL
    ck_assert_ptr_null(list);

} END_TEST

START_TEST(test_cb_list_ins_next_nullnode)
{
    CB_RETURN ret;
    CB_LIST *list;

    // Initialize objects
    cb_list_init(&list, &cb_list_destroy);

    ret = cb_list_ins_next(list, NULL, TEST_NODE_DATA, &cb_node_initialize_data);

    // Check if the function returns OK
    ck_assert_int_eq(ret, CB_OK);

    // If bot HEAD and TAIL are not NULL
    ck_assert_ptr_nonnull(list->head);
    ck_assert_ptr_nonnull(list->tail);

    // Check if the size increased
    ck_assert_int_eq(list->size, 1);

    // Check if both HEAD and TAIL contains the correct DATA
    ck_assert_str_eq(list->head->data, TEST_NODE_DATA);
    ck_assert_str_eq(list->tail->data, TEST_NODE_DATA);

    // Check if both HEAD and TAIL contains the correct ID
    ck_assert_int_eq(list->head->id, 1);
    ck_assert_int_eq(list->tail->id, 1);

    // Cleanup
    list->cb_list_destructor(&list);
} END_TEST

START_TEST(test_cb_list_ins_next_nullcallback)
{
    CB_RETURN ret;
    CB_LIST *list;
    CB_NODE node;

    // Initialize objects
    cb_list_init(&list, &cb_list_destroy);

    ret = cb_list_ins_next(list, &node, TEST_NODE_DATA, NULL);

    // Check if the function returns OK
    ck_assert_int_eq(ret, CB_OK);

    // If bot HEAD and TAIL are not NULL
    ck_assert_ptr_nonnull(list->head);
    ck_assert_ptr_nonnull(list->tail);

    // Check if the size increased
    ck_assert_int_eq(list->size, 1);

    // Check if both HEAD and TAIL contains the correct DATA
    ck_assert_str_eq(list->head->data, TEST_NODE_DATA);
    ck_assert_str_eq(list->tail->data, TEST_NODE_DATA);

    // Check if both HEAD and TAIL contains the correct ID
    ck_assert_int_eq(list->head->id, 1);
    ck_assert_int_eq(list->tail->id, 1);

    // Cleanup
    list->cb_list_destructor(&list);
} END_TEST

/*
START_TEST(test_cb_list_del_next)
{
    CB_RETURN cb_list_del_next(CB_LIST *list, CB_NODE *element, void **data);
} END_TEST

START_TEST(test_cb_list_get_size)
{
    CB_RETURN cb_list_get_size(const CB_LIST *list);
} END_TEST

START_TEST(test_cb_list_get_head)
{
    CB_NODE *cb_list_get_head(const CB_LIST *list);
} END_TEST

START_TEST(test_cb_list_get_tail)
{
    CB_NODE *cb_list_get_tail(const CB_LIST *list);
} END_TEST

START_TEST(test_cb_list_get_next)
{
    CB_NODE *cb_list_get_next(const CB_NODE *element);
} END_TEST

START_TEST(test_cb_list_is_head)
{
    CB_RETURN cb_list_is_head(const CB_NODE *element);
} END_TEST

START_TEST(test_cb_list_is_tail)
{
    CB_RETURN cb_list_is_tail(const CB_NODE *element);
} END_TEST
*/

Suite *cb_list_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_list");
    tc_core = tcase_create("TC_List");

    tcase_add_test(tc_core, test_cb_list_initialize);
    tcase_add_test(tc_core, test_cb_list_empty_destroy);
    tcase_add_test(tc_core, test_cb_list_empty_destroy_callback);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullcallback);

    suite_add_tcase(s, tc_core);

    return s;
}
