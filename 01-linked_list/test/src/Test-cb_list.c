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


START_TEST(test_cb_list_destroy)
{

} END_TEST

Suite *cb_list_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_list");
    tc_core = tcase_create("TC_List");

    tcase_add_test(tc_core, test_cb_list_initialize);
    tcase_add_test(tc_core, test_cb_list_destroy);

    suite_add_tcase(s, tc_core);

    return s;
}
