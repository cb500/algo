/**
 * CB_LIST: Tests of the "remove the next item from the list" (cb_list_del_next) function
 * Author: Charly Batista
 * Date: 2021-06-01
 **/

#include "Test-linked_list.h"

extern CB_LIST *tlist;
extern CB_RETURN tret;

void setup(void)
{
    CB_NODE *node;
    char data[30];

    // Initialize LIST object
    cb_list_init(&tlist, &cb_list_destroy);

    // Create the list of 10 nodes
    for(int i=0; i<10; i++)
    {
        sprintf(data, "%s %d", TEST_NODE_DATA, i);
        cb_list_ins_next(tlist, NULL, data, &cb_node_initialize_data);
        node = NULL;
    }
}

void teardown(void)
{
    // Destroys the list object
    tlist->cb_list_destructor(&tlist);
}

START_TEST(test_cb_list_del_next_nulllist)
{
    cb_list_del_next(NULL, NULL, NULL);
} END_TEST

START_TEST(test_cb_list_del_next_nulllist)
{
    cb_list_del_next(NULL, NULL, NULL);
} END_TEST


START_TEST(test_cb_list_del_next_nullnode)
{
    CB_LIST *null_list = NULL;
    ck_assert_ptr_nonnull(tlist);

    // Check if the function returns OK
    ck_assert_int_eq(tret, CB_OK);
} END_TEST


START_TEST(test_cb_list_del_next_nullnode)
{
    CB_LIST *null_list = NULL;
    ck_assert_ptr_nonnull(tlist);

    // Check if the function returns OK
    ck_assert_int_eq(tret, CB_OK);
} END_TEST


Suite *cb_list_del_next_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_list_del_next");
    tc_core = tcase_create("TC_List_del_next");

    tcase_add_checked_fixture(tc_core, setup, teardown);

    tcase_add_test(tc_core, );
    suite_add_tcase(s, tc_core);
    return s;
}