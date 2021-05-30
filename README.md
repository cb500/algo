# Algorithms and Data Structures

In computer science, a data structure is a data organization, management, and storage format that enables efficient access and modification. More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data. [1]

Algorithms are well-defined procedures for solving problems. In computing, algorithms are essential because they serve as the systematic procedures that computers require. A good algorithm is like using the right tool in a workshop. It does the job with the right amount of effort. Using the wrong algorithm or one that is not clearly defined is like cutting a piece of paper with a table saw, or trying to cut a piece of plywood with a pair of scissors: although the job may get done, you have to wonder how effective you were in completing it. As with data structures, three reasons for using formal algorithms are efficiency, abstraction, and reusability. [2]

This repo contains code of some data structures implementations. They are not meant to be performatic in any way and are here just for learning and academic purpose. During this training we are using few books as references. The organization of the topics and the interfaces are based on "Mastering Algorithms with C" by Kyle Loudon[2]:
 - Linked Lists
 - Stacks
 - Queues
 - Sets
 - Hash Tables
 - Trees
 - Heaps and Priority Queues
 - Graphs
 - Sorting
 - Searching

We may visit Data Compression and Data Encryption if the time allows.

## How to use the code
Every folder (module) has a makefile inside with all the rules to automatically build the executables for that "module". The binaries will be placed into the subfolder "objs" with the name of the module excluding the numeral value in front of the name. For example, the module "01-linked_list" will have the binary "objs/linked_list", the "03-queue" will be "objs/queue" and so on.

The instructions to execute the tests, the binaries and the requered parameters will be described in a README file inside of each module.

## Boosks and Refereces
Thes books used here as references, ideas and help to understand the concepts are:
 - Mastering Algorithms with C by Kyle Loudon[2]
 - Data Structures: A Pseudocode Approach with C, 2nd Edition by Richard F. Gilberg  and Behrouz A. Forouzan [3]
 - Algorithms by Robert Sedgewick & Kevin Wayne [4][5]
 - The Algorithm Design Manual by Steve S. Skiena [6]
 - Wikipedia

[1] https://en.wikipedia.org/wiki/Data_structure
[2] https://www.oreilly.com/library/view/mastering-algorithms-with/1565924533/
[3] https://www.amazon.com/Data-Structures-Pseudocode-Approach-C/dp/0534390803
[4] https://www.amazon.com/Algorithms-4th-Robert-Sedgewick/dp/032157351X
[5] https://algs4.cs.princeton.edu/home/
[6] https://www.springer.com/gp/book/9781848000698