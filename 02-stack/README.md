# Stacks

A stack is a basic data structure that can be logically thought of as a linear structure represented by a real physical stack or pile, a structure where insertion and deletion of items takes place at one end called top of the stack. The basic concept can be illustrated by thinking of your data set as a stack of plates or books where you can only take the top item of the stack in order to remove things from it. This structure is used all throughout programming.

The basic implementation of a stack is also called a LIFO (Last In First Out) to demonstrate the way it accesses data, since as we will see there are various variations of stack implementations.

There are basically three operations that can be performed on stacks. They are:
- inserting an item into a stack (push).
- deleting an item from the stack (pop).
- displaying the contents of the stack (peek or top).[1]

One way to implement a stack is as a linked list. As we already have one linked list we could simply typedef our Stack object to the List object we have and reuse the appropriated methods (functions), for example:
```c
#include <cb_list.c>

typedef CB_LIST CB_STACK;

#define cb_stack_init cb_list_init
#define cb_stack_destroy cb_list_destroy
#define cb_stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)
#define cb_stack_get_size cb_list_get_size
```
This way we already have most of our stack implemented.

I will use this approach here and leave the full implementation as an exercise.

Also, note that some the test cases are implemented but from this point the majority of them will be left as exercise.

[1] https://en.wikibooks.org/wiki/Data_Structures/Stacks_and_Queues