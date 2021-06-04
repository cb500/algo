/**
 * CB_LIST: Tests of the list get and check functions
 * Author: Charly Batista
 * Date: 2021-05-31
 **/

#include "Test-linked_list.h"

extern CB_LIST *tlist;
extern CB_RETURN tret;
extern CB_NODE *tnode;
extern char *tdata;

void test_cb_list_get_next_setup(void)
{
    char tmp_data[30];
    tlist = NULL;
    tnode = NULL;

    // Initialize LIST object
    cb_list_init(&tlist, &cb_list_destroy);

    // Create the list of 10 nodes
    for(int i=0; i<10; i++)
    {
        sprintf(tmp_data, "%s %d", TEST_NODE_DATA, i);
        cb_list_ins_next(tlist, NULL, tmp_data, &cb_node_initialize_data);
        tnode = NULL;
    }
}

void test_cb_list_get_next_teardown(void)
{
    // Destroys the list object
    tlist->cb_list_destructor(&tlist);
}

// The list cannot be NULL
START_TEST(test_cb_list_get_size_nulllist)
{
    tret = cb_list_get_size(NULL);
    ck_assert_int_eq(tret, CB_ERR_NULL);
} END_TEST

START_TEST(test_cb_list_get_size)
{
    tret = cb_list_get_size(tlist);
    ck_assert_int_eq(tret, 10);
} END_TEST



Suite *cb_list_get_next_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_list_get_next");
    tc_core = tcase_create("TC_List_del_next");

    tcase_add_checked_fixture(tc_core, test_cb_list_get_next_setup, test_cb_list_get_next_teardown);

    tcase_add_test(tc_core, test_cb_list_get_size_nulllist);
    tcase_add_test(tc_core, test_cb_list_get_size);
    suite_add_tcase(s, tc_core);
    return s;
}