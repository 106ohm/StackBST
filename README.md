# StackBST
stack-based Binary Search Tree (BST) implemented in the "struct of arrays" style.
Actually, this is strongly inspired by the [geeksforgeeks](https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion) version.

## Implementation choices
* stack-based, i.e., no dynamic memory. A chunck of memory is allocated at the beginning and cells are referred through integer indices. Total memory usage: (4*N+1)*5 bytes or so
* "struct of arrays" style, i.e., there is no "node" structure so that key, left and right pointers are stored in arrays
* the free list (data structure for custom memory allocation) is implemented through the nextInFreeList array, whose entries are -1 if the node is allocated and nonnegative otherwise, and freeListHead that points to the free list head
