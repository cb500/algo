/**
 * CB_NODE tests
 * Author: Charly Batista
 * Date: 2021-05-30
 **/

#include <check.h>
#include <stdlib.h>
#include "cb_node.h"

/*
CB_RETURN cb_node_initialize(void **new_node);
void cb_node_destroy(void *node);
void cb_print_node(void *node);
CB_RETURN cb_node_add_data(CB_NODE *node, char *value);
void *cb_node_get_data(CB_NODE *node, void *(*cb_get_data)(CB_NODE *node));
*/

START_TEST(test_cb_node_initialize) 
{
    CB_NODE *node;
    int ret;
    extern CB_RETURN cb_node_initialize(void **);

    ret = cb_node_initialize((void **)&node);
    ck_assert_int_eq(ret, CB_OK);
    ck_assert_ptr_nonnull(node);

    cb_node_destroy(node);
} END_TEST

Suite *money_suite(void) 
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_node");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_cb_node_initialize);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) 
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = money_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}