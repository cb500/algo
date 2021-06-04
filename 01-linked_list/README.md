# Linked Lists

Linked lists are some of the most fundamental data structures in computer science. It is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions. A drawback of linked lists is that access time is linear (and difficult to pipeline). Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists.

Linked lists are among the simplest and most common data structures. They can be used to implement several other common abstract data types, including lists, stacks, queues, associative arrays, and S-expressions, though it is not uncommon to implement those data structures directly without using a linked list as the basis.[1]

### How to build and run the tests
There is a makefile with the formulas to make the project and also the tests:
- `make`: will build the project using the `src/cb_main.c` file. The binary is placed into the `build` sub-folder as `build/linked_list`. There is no much in the `cb_main.c` file now, it just create one list with 30 elements and print it to the console;
    - `build/linked_list`: The makefile doesn't execute the binary, it needs to be ran manually with something like `build/linked_list`;
- `make test`: builds and execute the tests and if everything goes well will print something like:
    ```bash
    Creating directories build
    Compiling project file 'src/cb_node.c' to create 'build/cb_node.o'
    Compiling project file 'src/cb_list.c' to create 'build/cb_list.o'
    Compiling test file 'test/src/Test-cb_node.c' to create 'build/Test-cb_node.o'
    Compiling test file 'test/src/Test-main.c' to create 'build/Test-main.o'
    Compiling test file 'test/src/Test-cb_list-add_next.c' to create 'build/Test-cb_list-add_next.o'
    Compiling test file 'test/src/Test-cb_list-init.c' to create 'build/Test-cb_list-init.o'
    Compiling test file 'test/src/Test-cb_list-del_next.c' to create 'build/Test-cb_list-del_next.o'
    Compiling test file 'test/src/Test-cb_list-find.c' to create 'build/Test-cb_list-find.o'
    Compiling test file 'test/src/Test-cb_list-get.c' to create 'build/Test-cb_list-get.o'
    Building the test binary (linked_list-test) out of build/cb_node.o build/cb_list.o build/Test-cb_node.o build/Test-main.o build/Test-cb_list-add_next.o build/Test-cb_list-init.o build/Test-cb_list-del_next.o build/Test-cb_list-find.o build/Test-cb_list-get.o

    --- TESTS BEGIN ------------------------------------
    build/linked_list-test
    Running suite(s): cb_node
    cb_list_init
    cb_list_add_next
    cb_list_del_next
    cb_list_find
    100%: Checks: 38, Failures: 0, Errors: 0

    ---- TESTS END --------------------------------------
    ```
- `make lib`: creates the `.so` library file using the project code files excluding the `cb_main.c`
- `make coverage`: build, runs the tests and create the coverage files using `gcov`[2], which is a tool we can use in conjunction with GCC to test code coverage in our programs
- `make valgrind`: runs valgrind[3] against the test and project binary files (if exists)
- `make clean`: removes the `build` folder and all binary files;

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
The implementation of the linked list here is based on the description given by Kyle Loudon in his book `Mastering Algorithms with C` with some modifications.
As also done in his implementation, here, the structure `CB_LIST` is the linked list data structure, but here we don't implement the `match` function as we intend to keep each implementation as clean as possible to make it more easier to be understood. The `CB_LIST` consists of four members:
    - `size`: the number of elements in the list;
    - `destroy`: the encapsulated destroy function passed to `cb_list_init` function, which will be later used to destroy the list and do the clean up;
    - `head`: a pointer to the first of the linked elements;
    - `tail`: a pointer to the tail (last) element of the list.

As we can see here this is not a circular or a double linked list implementation but a single linked list implementation. It has a lot of space for improvements and they are very wellcomed.

The `CB_NODE` is the node element of the linked list and it consists of three parts:
    - `id`: the node identifier, also represents the position of the node in the list (not really implemented here and left as `TODO`);
    - `data`: the node data member, it is a generic pointer to `void` and can, theoretically, hold any data but the implementation here mostly expects string;
    - `next`: a pointer to the next element in the list.

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

[1] https://en.wikipedia.org/wiki/Linked_list <br>
[2] https://gcc.gnu.org/onlinedocs/gcc/Gcov.html <br>
[3] https://valgrind.org/