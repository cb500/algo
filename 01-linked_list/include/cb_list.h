/**
 * Header and interface of the List implementation
 * Author: Charly Batista
 * Date: 2021-05-28
 **/

#ifndef __CB_LIST_H
#define __CB_LIST_H

#include <sys/types.h>
#include "cb_node.h"

typedef struct _CB_LIST CB_LIST;
struct _CB_LIST
{
    CB_NODE *head;
    CB_NODE *tail;
    u_int32_t size;
    void (*cb_list_destructor)(CB_LIST **list);
};

/**
 * Initializes the linked list specified by list. This operation must be called for a linked list before the list can be used with any other operation.
 * The destroy argument provides a way to free dynamically allocated data when list_destroy is called.
 * For example, if the list contains data dynamically allocated using malloc, destroy should be set to free to free the data as the linked list is destroyed.
 * For structured data containing several dynamically allocated members, destroy should be set to a user-defined function that calls free for each dynamically
 *      allocated member as well as for the structure itself.
 * For a linked list containing data that should not be freed, destroy should be set to NULL.
 * @param  list
 * @param  list_destructor_callback
 * @return CB_OK if successful, or the appropriated CB_ERROR otherwise
 *
 */
CB_RETURN cb_list_init(CB_LIST **list, void (*cb_list_destructor_callback)(CB_LIST **list));

/**
 * Destroys the linked list specified by list.
 * No other operations are permitted after calling list_destroy unless list_init is called again.
 * The list_destroy operation removes all elements from a linked list and calls the function passed as destroy to list_init 
 *      once for each element as it is removed, provided destroy was not set to NULL.
 * @param  list
 * @return void
 *
 */
void cb_list_destroy(CB_LIST **list);

/**
 * Inserts an element just after element in the by list.
 * If element is NULL, the new element is inserted at the new element contains a pointer to data, so the memory should
 *      remain valid as long as the element remains in the list.
 * ity of the caller to manage the storage associated with data.
 * @param  list
 * @param  element
 * @param  data
 * @param  node_initialize_callback
 * @return CB_OK if successful, or the appropriated CB_ERROR otherwise
 *
 */
CB_RETURN cb_list_ins_next(CB_LIST *list, CB_NODE *element, const void *data, CB_RETURN (*cb_node_initialize_callback)(CB_NODE **nde, const void *dta));

/**
 * Removes the NODE element just after element from the linked list specified by "criteria".
 * If "criteria" element is NULL, the element at the head of the list is removed.
 * Upon return, REMOVED points to the NODE that was just removed.
 * It is the responsibility of the caller to manage the storage associated with the removed NODE.
 * @param  list the list to operate on
 * @param  criteria The NODE element to evaluate and find the next NODE to remove
 * @param  removed The NODE that was removed from the list
 * @return CB_OK if successful, or the appropriated CB_ERROR otherwise
*/
CB_RETURN cb_list_del_next(CB_LIST *list, CB_NODE *criteria, CB_NODE **removed);

/**
 * Find and return a NODE element using a callback function
 * @param  list
 * @param  params
 * @param cb_list_find_callback
 * @return CB_NODE if the element is found in the list
 *         NULL if not found
 */
CB_NODE *cb_list_find(const CB_LIST *list, const void *params, CB_NODE *(*cb_list_find_callback)(const CB_LIST *lst, const void *prams));

/**
 * Search for a NODE using the DATA. It will return the 1st found element or NULL in case of not found element
 * @param  list
 * @param  params
 * @return CB_NODE if the element is found in the list
 *         NULL if not found
 */
CB_NODE *cb_list_find_by_data(const CB_LIST *list, const void *params);

/**
 * Return the NODE at the specified position
 * @param  list
 * @param  params
 * @return CB_NODE if the element is found in the list
 *         NULL if not found
 */
CB_NODE *cb_list_find_by_pos(const CB_LIST *list, const ssize_t pos);

/**
 * Gets the number of elements in the linked list specified by list.
 * @param  list
 * @return Number of elements in the list
 */
ssize_t cb_list_get_size(const CB_LIST *list);

/**
 * Gets the head of the linked list specified by list.
 * @param  list
 * @return Element at the head of the list
 */
CB_NODE *cb_list_get_head(const CB_LIST *list);

/**
 * Gets the tail of the linked list specified by list.
 * @param  list
 * @return Element at the tail of the list
 */
CB_NODE *cb_list_get_tail(const CB_LIST *list);

/**
 * Gets the tail of the linked list specified by list.
 * @param  list
 * @param  element
 * @return Element following the specified element.
 *      It will return NULL if:
 *          - The list is NULL
 *          - Not specified or NULL element
 *          - The specified element doesn't exist in the list
 *          - The specified element is the tail (last element) of the list
 */
CB_NODE *cb_list_get_next(const CB_LIST *list, const CB_NODE *element);

/**
 * Determines whether the element specified as element is at the head of the linked list.
 * @param  list
 * @param  element
 * @return CB_TRUE if the element is at the head of the list
 *         CB_FALSE otherwise.
 */
CB_BOOL cb_list_is_head(const CB_LIST *list, const CB_NODE *element);

/**
 * Determines whether the element specified as element is at the tail of the linked list.
 * @param  list
 * @param  element
 * @return CB_TRUE if the element is at the tail of the list
 *         CB_FALSE otherwise.
 */
CB_RETURN cb_list_is_tail(const CB_NODE *element);

/**
 * Traverse the list printing all the node's data
 * @param
 * @return
 */
void cb_list_traverse(CB_LIST *list);

#endif  // __CB_LIST_H