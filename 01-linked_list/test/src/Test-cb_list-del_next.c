/**
 * CB_LIST: Tests of the "remove the next item from the list" (cb_list_del_next) function
 * Author: Charly Batista
 * Date: 2021-06-01
 **/

#include "Test-linked_list.h"

extern CB_LIST *tlist;
extern CB_RETURN tret;

#ifndef tnode
CB_NODE *tnode;
#endif

#ifndef tdata
char *tdata;
#endif

void test_cb_list_del_next_setup(void)
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

void test_cb_list_del_next_teardown(void)
{
    // Destroys the list object
    tlist->cb_list_destructor(&tlist);
}

// The list cannot be NULL
START_TEST(test_cb_list_del_next_nulllist)
{
    tret = cb_list_del_next(NULL, NULL, NULL);
    ck_assert_int_eq(tret, CB_ERR_NULL);
} END_TEST

// The node can be NULL but the returned data cannot be null
// because it is the USER's responsability to free the memory
START_TEST(test_cb_list_del_next_nullnode_nulldata)
{
    tret = cb_list_del_next(tlist, NULL, NULL);
    ck_assert_int_eq(tret, CB_ERR_NULL);
} END_TEST


START_TEST(test_cb_list_del_next_nullnode_OK)
{
    tret = cb_list_del_next(tlist, NULL, &tnode);
    ck_assert_int_eq(tret, CB_OK);
} END_TEST


START_TEST(test_cb_list_del_next_nullnode_data_nonnull)
{
    cb_node_initialize(&tnode);
    cb_list_del_next(tlist, NULL, &tnode);
    ck_assert_ptr_nonnull(tnode->data);
} END_TEST

START_TEST(test_cb_list_del_next_nullnode_data)
{
    char tmp_data[30];
    sprintf(tmp_data, "%s %d", TEST_NODE_DATA, 9);

    cb_list_del_next(tlist, NULL, &tnode);
    ck_assert_str_eq(tnode->data, tmp_data);
} END_TEST

START_TEST(test_cb_list_del_next_nullnode)
{
    cb_list_del_next(tlist, NULL, &tnode);
    printf("\nOld Head: %s\nNew Head: %s\n\n", (char *)tnode->data, (char *)tlist->head->data);
    ck_assert_ptr_ne(tnode, tlist->head);
} END_TEST

START_TEST(test_cb_list_del_next_nullnode_nextnode)
{
    CB_NODE *node_next;
    node_next = tlist->head->next;

    cb_list_del_next(tlist, NULL, &tnode);
    ck_assert_ptr_eq(node_next, tlist->head);
} END_TEST

//------------------------------------------------------
START_TEST(test_cb_list_del_next_nulldata)
{
    tnode = tlist->head;
    tret = cb_list_del_next(tlist, tnode, NULL);
    ck_assert_int_eq(tret, CB_ERR_NULL);
} END_TEST


START_TEST(test_cb_list_del_next_OK)
{
    tret = cb_list_del_next(tlist, tlist->head, &tnode);
    ck_assert_int_eq(tret, CB_OK);
} END_TEST

START_TEST(test_cb_list_del_next_data_nonnull)
{
    cb_list_del_next(tlist, tlist->head, &tnode);
    ck_assert_ptr_nonnull(tnode);
} END_TEST

START_TEST(test_cb_list_del_next)
{
    CB_NODE *tmp_node = tlist->head->next;

    cb_list_del_next(tlist, tlist->head, &tnode);
    ck_assert_ptr_eq(tmp_node, tnode);
} END_TEST

START_TEST(test_cb_list_del_next_data)
{
    char tmp_data[30];
    sprintf(tmp_data, "%s %d", TEST_NODE_DATA, 8);

    cb_list_del_next(tlist, tlist->head, &tnode);
    ck_assert_str_eq(tmp_data, tnode->data);
} END_TEST

START_TEST(test_cb_list_del_next_head)
{
    CB_NODE *tmp_node = tlist->head;

    cb_list_del_next(tlist, tlist->head, &tnode);
    ck_assert_ptr_eq(tmp_node, tlist->head);
} END_TEST

START_TEST(test_cb_list_del_next_nextnode)
{
    CB_NODE *node_next;
    node_next = tlist->head->next;

    cb_list_del_next(tlist, tlist->head, &tnode);
    ck_assert_ptr_ne(node_next, tlist->head->next);
} END_TEST

START_TEST(test_cb_list_del_next_tail)
{
    //CB_NODE *node_next;
    //node_next = tlist->head->next;

    cb_list_del_next(tlist, tlist->tail, &tnode);
    ck_assert_ptr_null(tnode);
} END_TEST

//------------------------------------------------------


Suite *cb_list_del_next_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_list_del_next");
    tc_core = tcase_create("TC_List_del_next");

    tcase_add_checked_fixture(tc_core, test_cb_list_del_next_setup, test_cb_list_del_next_teardown);

    tcase_add_test(tc_core, test_cb_list_del_next_nulllist);
    tcase_add_test(tc_core, test_cb_list_del_next_nullnode_nulldata);
    tcase_add_test(tc_core, test_cb_list_del_next_nullnode_OK);
    tcase_add_test(tc_core, test_cb_list_del_next_nullnode_data_nonnull);
    tcase_add_test(tc_core, test_cb_list_del_next_nullnode_data);
    tcase_add_test(tc_core, test_cb_list_del_next_nullnode);
    tcase_add_test(tc_core, test_cb_list_del_next_nullnode_nextnode);

    tcase_add_test(tc_core, test_cb_list_del_next_nulldata);
    tcase_add_test(tc_core, test_cb_list_del_next_OK);
    tcase_add_test(tc_core, test_cb_list_del_next_data_nonnull);
    tcase_add_test(tc_core, test_cb_list_del_next);
    tcase_add_test(tc_core, test_cb_list_del_next_data);
    tcase_add_test(tc_core, test_cb_list_del_next_head);
    tcase_add_test(tc_core, test_cb_list_del_next_nextnode);
    tcase_add_test(tc_core, test_cb_list_del_next_tail);
    suite_add_tcase(s, tc_core);
    return s;
}