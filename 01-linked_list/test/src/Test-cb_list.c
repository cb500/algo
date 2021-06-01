/**
 * CB_LIST tests
 * Author: Charly Batista
 * Date: 2021-05-31
 **/

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

Suite *cb_list_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("cb_list");
    tc_core = tcase_create("TC_List");

    tcase_add_test(tc_core, test_cb_list_initialize);
    tcase_add_test(tc_core, test_cb_list_empty_destroy);
    tcase_add_test(tc_core, test_cb_list_empty_destroy_callback);
    tcase_add_test(tc_core, test_cb_list_ins_next_init_list);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_init);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_head);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_tail);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_size);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_head_data);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_tail_data);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_head_id);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullnode_tail_id);
    tcase_add_test(tc_core, test_cb_list_ins_next_nullcallback);

    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );
    tcase_add_test(tc_core, );


    suite_add_tcase(s, tc_core);

    return s;
}
*/