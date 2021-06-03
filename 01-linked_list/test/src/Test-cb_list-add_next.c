/**
 * CB_LIST: Tests of the "add next item to the list" (cb_list_ins_next) function
 * Author: Charly Batista
 * Date: 2021-05-31
 **/

#include "Test-linked_list.h"

extern CB_LIST *tlist;
extern CB_RETURN tret;

void setup(void)
{
    // Initialize LIST object
    cb_list_init(&tlist, &cb_list_destroy);
    tret = cb_list_ins_next(tlist, NULL, TEST_NODE_DATA, &cb_node_initialize_data);
}

void teardown(void)
{
    // Destroys the list object
    tlist->cb_list_destructor(&tlist);
}

START_TEST(test_cb_list_ins_next_nulllist)
{
    cb_list_ins_next(NULL, NULL, TEST_NODE_DATA, &cb_node_initialize_data);

    // Check if the function returns OK
    ck_assert_int_eq(tret, CB_OK);
} END_TEST


START_TEST(test_cb_list_ins_next_nullnode_init)
{
    ck_assert_ptr_nonnull(tlist);

    // Check if the function returns OK
    ck_assert_int_eq(tret, CB_OK);
} END_TEST

START_TEST(test_cb_list_ins_next_nullnode_head)
{
    ck_assert_ptr_nonnull(tlist);
    ck_assert_ptr_nonnull(tlist->head);
} END_TEST

START_TEST(test_cb_list_ins_next_nullnode_tail)
{
    ck_assert_ptr_nonnull(tlist->tail);
} END_TEST

START_TEST(test_cb_list_ins_next_nullnode_size)
{
    ck_assert_int_eq(tlist->size, 1);
} END_TEST

START_TEST(test_cb_list_ins_next_nullnode_head_data)
{
    ck_assert_str_eq(tlist->head->data, TEST_NODE_DATA);
} END_TEST

START_TEST(test_cb_list_ins_next_nullnode_tail_data)
{
    ck_assert_str_eq(tlist->tail->data, TEST_NODE_DATA);
} END_TEST

START_TEST(test_cb_list_ins_next_nullcallback)
{
    CB_LIST *list;
    CB_NODE node;

    // Initialize objects
    cb_list_init(&list, &cb_list_destroy);

    tret = cb_list_ins_next(list, &node, TEST_NODE_DATA, NULL);

    // Check if the function returns OK
    ck_assert_int_eq(tret, CB_OK);

    // If both HEAD and TAIL are not NULL
    ck_assert_ptr_nonnull(list->head);
    ck_assert_ptr_nonnull(list->tail);

    // Check if the size increased
    ck_assert_int_eq(list->size, 1);

    // Check if both HEAD and TAIL contains the correct DATA
    ck_assert_str_eq(list->head->data, TEST_NODE_DATA);
    ck_assert_str_eq(list->tail->data, TEST_NODE_DATA);

    // Destroys the list object
    tlist->cb_list_destructor(&list);
} END_TEST

Suite *cb_list_add_next_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_list_add_next");
    tc_core = tcase_create("TC_List_add_next");

    tcase_add_checked_fixture(tc_core, setup, teardown);

    tcase_add_test(tc_core, test_cb_list_ins_next_nulllist);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_init);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_head);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_tail);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_size);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_head_data);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_tail_data);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullcallback);
    suite_add_tcase(s, tc_core);
    return s;
}