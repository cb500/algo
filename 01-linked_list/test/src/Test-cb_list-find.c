/**
 * CB_LIST: Tests of the list find functions
 * Author: Charly Batista
 * Date: 2021-06-03
 **/

#include "Test-linked_list.h"

extern CB_LIST *tlist;
extern CB_RETURN tret;
extern CB_NODE *tnode;
extern char *tdata;

// Local variable
CB_NODE *tnode_arr[5];

void test_cb_list_find_setup(void)
{
    char tmp_data[30];
    tlist = NULL;
    tnode = NULL;

    // Initialize LIST object
    cb_list_init(&tlist, &cb_list_destroy);

    // Create the list of 10 nodes
    for(int i=0; i<30; i++)
    {
        sprintf(tmp_data, "%s %d", TEST_NODE_DATA, i);
        cb_list_ins_next(tlist, NULL, tmp_data, &cb_node_initialize_data);

        switch (i)
        //29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0
        //0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
        {
        case 4: // Position number 25
            tnode_arr[0] = tlist->head;
            break;
        case 13: // Position number 16
            tnode_arr[1] = tlist->head;
            break;
        case 19: // Position number 10
            tnode_arr[2] = tlist->head;
            break;
        case 23: // Position number 6
            tnode_arr[3] = tlist->head;
            break;
        case 28: // Position number 1
            tnode_arr[4] = tlist->head;
            break;
        default:
            break;
        }
        tnode = NULL;
    }
}

void test_cb_list_find_teardown(void)
{
    // Destroys the list object
    tlist->cb_list_destructor(&tlist);
}

//START_TEST(test_)
START_TEST(test_cb_list_find_by_pos_null)
{
    tnode = cb_list_find_by_pos(tlist, 40);
    ck_assert_ptr_null(tnode);
} END_TEST

START_TEST(test_cb_list_find_by_pos_nonnull)
{
    tnode = cb_list_find_by_pos(tlist, 4);
    ck_assert_ptr_nonnull(tnode);
} END_TEST

START_TEST(test_cb_list_find_by_pos_val)
{
    tnode = cb_list_find_by_pos(tlist, 16);
    ck_assert_str_eq(tnode->data, tnode_arr[1]->data);
} END_TEST

START_TEST(test_cb_list_find_by_pos)
{
    tnode = cb_list_find_by_pos(tlist, 10);
     ck_assert_ptr_eq(tnode, tnode_arr[2]);
} END_TEST

//------------------------------
START_TEST(test_cb_list_find_by_data_null)
{
    char tmp_data[] = "Not found";

    tnode = cb_list_find_by_data(tlist, (void *)tmp_data);
    ck_assert_ptr_null(tnode);
} END_TEST

START_TEST(test_cb_list_find_by_data_nonnull)
{
    char tmp_data[30];
    sprintf(tmp_data, "%s %d", TEST_NODE_DATA, 23);

    tnode = cb_list_find_by_data(tlist, (void *)tmp_data);
    ck_assert_ptr_nonnull(tnode);
} END_TEST

START_TEST(test_cb_list_find_by_data)
{
    char tmp_data[30];
    sprintf(tmp_data, "%s %d", TEST_NODE_DATA, 28);

    tnode = cb_list_find_by_data(tlist, (void *)tmp_data);
    ck_assert_ptr_eq(tnode, tnode_arr[4]);
} END_TEST

START_TEST(test_cb_list_find)
{
    char tmp_data[30];
    sprintf(tmp_data, "%s %d", TEST_NODE_DATA, 4);

    tnode = cb_list_find(tlist, (void *)tmp_data, &cb_list_find_by_data);
    ck_assert_ptr_eq(tnode, tnode_arr[0]);
} END_TEST

Suite *cb_list_find_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_list_find");
    tc_core = tcase_create("TC_List_find");

    tcase_add_checked_fixture(tc_core, test_cb_list_find_setup, test_cb_list_find_teardown);

    tcase_add_test(tc_core, test_cb_list_find_by_pos_null);
    tcase_add_test(tc_core, test_cb_list_find_by_pos_nonnull);
    tcase_add_test(tc_core, test_cb_list_find_by_pos_val);
    tcase_add_test(tc_core, test_cb_list_find_by_pos);
    tcase_add_test(tc_core, test_cb_list_find_by_data_null);
    tcase_add_test(tc_core, test_cb_list_find_by_data_nonnull);
    tcase_add_test(tc_core, test_cb_list_find_by_data);
    tcase_add_test(tc_core, test_cb_list_find);
    suite_add_tcase(s, tc_core);
    return s;
}