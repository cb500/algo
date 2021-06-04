# Linked Lists

Linked lists are some of the most fundamental data structures in computer science. It is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions. A drawback of linked lists is that access time is linear (and difficult to pipeline). Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists.

Linked lists are among the simplest and most common data structures. They can be used to implement several other common abstract data types, including lists, stacks, queues, associative arrays, and S-expressions, though it is not uncommon to implement those data structures directly without using a linked list as the basis.[1]

### Defined types
We have some types defined in the `<root>/include/cb_types.h` file which are:
```c
/**
 * CB_RETURN
 * Custom numeric type used to help to improve error handler
 */
typedef enum
{
    CB_OK            = 0,
    CB_ERR_MEM_INIT  = -1,
    CB_ERR_NULL      = -2,
    CB_ERR_GENERIC   = -99
} CB_RETURN;

/**
 * CB_BOOL
 * Custom boolean type that uses <stdbool.h> boolean types if defined (C99) or an user-defined structure like below
 */
typedef enum
{
    CB_FALSE         = 0,
    CB_TRUE          = 1
} CB_BOOL;
```

## Interface of our Linked List implementation
The custom types here are defined in `<root>/01-linked_list/include/cb_node.h` (*CB_NODE*) and `<root>/01-linked_list/include/cb_list.h` (*CB_LIST*) header files.
The full description of the interface functions can be found inside `<root>/01-linked_list/include/cb_list.h` header file.

```c
/**
 * Initializes the linked list specified by list.
 */
CB_RETURN cb_list_init(CB_LIST **list, void (*cb_list_destructor_callback)(CB_LIST **list));

/**
 * Destroys the linked list specified by list.
 */
void cb_list_destroy(CB_LIST **list);

/**
 * Inserts an element just after element in the by list.
 */
CB_RETURN cb_list_ins_next(CB_LIST *list, CB_NODE *element, const void *data, CB_RETURN (*cb_node_initialize_callback)(CB_NODE **nde, const void *dta));

/**
 * Removes the NODE element just after element from the linked list specified by "criteria".
*/
CB_RETURN cb_list_del_next(CB_LIST *list, CB_NODE *criteria, CB_NODE **removed);

/**
 * Find and return a NODE element using a callback function.
 */
CB_NODE *cb_list_find(const CB_LIST *list, const void *params, CB_NODE *(*cb_list_find_callback)(const CB_LIST *lst, const void *prams));

/**
 * Search for a NODE using the DATA. It will return the 1st found element or NULL in case of not found element.

 */
CB_NODE *cb_list_find_by_data(const CB_LIST *list, const void *params);

/**
 * Return the NODE at the specified position.

 */
CB_NODE *cb_list_find_by_pos(const CB_LIST *list, const ssize_t pos);

/**
 * Gets the number of elements in the linked list specified by list.
 */
size_t cb_list_get_size(const CB_LIST *list);

/**
 * Gets the head of the linked list specified by list.
 */
CB_NODE *cb_list_get_head(const CB_LIST *list);

/**
 * Gets the tail of the linked list specified by list.
 */
CB_NODE *cb_list_get_tail(const CB_LIST *list);

/**
 * Gets the tail of the linked list specified by list.
 */
CB_NODE *cb_list_get_next(const CB_LIST *list, const CB_NODE *element);

/**
 * Determines whether the element specified as element is at the head of the linked list.
 */
CB_BOOL cb_list_is_head(const CB_LIST *list, const CB_NODE *element);

/**
 * Determines whether the element specified as element is at the tail of the linked list.
 */
CB_BOOL cb_list_is_tail(const CB_LIST *list, const CB_NODE *element);

/**
 * Traverse the list printing all the node's data.
 */
CB_RETURN cb_list_traverse(const CB_LIST *list);
```

[1] https://en.wikipedia.org/wiki/Linked_list
