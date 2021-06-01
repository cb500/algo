/**
 * CB_LIST: Tests of the initialization functions
 * Author: Charly Batista
 * Date: 2021-05-31
 **/


#include "Test-linked_list.h"

extern CB_LIST *tlist;
extern CB_RETURN tret;

START_TEST(test_cb_list_init)
{
    // Initialize the node
    tret = cb_list_init(&tlist, &cb_list_destroy);

    // Check if the return is OK
    ck_assert_ptr_nonnull(tlist);
} END_TEST

START_TEST(test_cb_list_init_null)
{
    // Check if the node isn't NULL
    cb_list_init(&tlist, &cb_list_destroy);
    ck_assert_ptr_nonnull(tlist);
} END_TEST


START_TEST(test_cb_list_empty_destroy)
{
    // Destroy the node
    cb_list_init(&tlist, &cb_list_destroy);
    ck_assert_ptr_nonnull(tlist);
    cb_list_destroy(&tlist);

    // Check if the node is really NULL
    ck_assert_ptr_null(tlist);
} END_TEST

START_TEST(test_cb_list_empty_destroy_callback)
{
    // Initialize the node
    cb_list_init(&tlist, &cb_list_destroy);
    ck_assert_ptr_nonnull(tlist);

    // Destroy the node
    tlist->cb_list_destructor(&tlist);

    // Check if the node is really NULL
    ck_assert_ptr_null(tlist);
} END_TEST


Suite *cb_list_init_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_list_init");
    tc_core = tcase_create("TC_List_Init");

    tcase_add_test(tc_core, test_cb_list_init);
    tcase_add_test(tc_core, test_cb_list_init_null);
    tcase_add_test(tc_core, test_cb_list_empty_destroy);
    tcase_add_test(tc_core, test_cb_list_empty_destroy_callback);
    suite_add_tcase(s, tc_core);

    return s;
}