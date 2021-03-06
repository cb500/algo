/**
 * MAIN test file responsible to run all the tests
 * Author: Charly Batista
 * Date: 2021-05-31
 **/

#include <check.h>
#include <stdlib.h>
#include "Test-linked_list.h"

CB_LIST *tlist = NULL;
CB_RETURN tret = 0;
CB_NODE *tnode;
char *tdata;


int main(void)
{
    int no_failed = 0;
    //Suite *s;
    SRunner *runner;

    runner = srunner_create(cb_node_suite());
    srunner_add_suite(runner, cb_list_init_suite());
    srunner_add_suite(runner, cb_list_add_next_suite());
    srunner_add_suite(runner, cb_list_del_next_suite());
    srunner_add_suite(runner, cb_list_find_suite());

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
