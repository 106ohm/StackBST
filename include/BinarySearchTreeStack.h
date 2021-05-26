#ifndef BINARYSEARCHTREESTACK_H
#define BINARYSEARCHTREESTACK_H

/* This generated file contains includes for project dependencies */
#include "BinarySearchTreeStack/bake_config.h"

#define N 10

/* Binary Search Tree (BST) implementation choices:
 - stack-based, i.e., no dynamic memory. A chunck of
   memory is allocated at the beginning and cells
   are referred through integer indices.
   Total memory usage: (4*N+1)*5 bytes 
 - struct of array style, i.e., there is no "node" structure
   so that key, left and right pointers are stored
   in arrays
 - the free list (data structure for custom memory allocation)
   is implemented through the nextInFreeList array,
   whose entries are -1 if the node is allocated 
   and nonnegative otherwise, and freeListHead that points
   to the free list head
 */ 

typedef struct Mem {
  // tree nodes related:
  double key[N];
  int left[N];
  int right[N];
  // free list related:
  int nextInFreeList[N];
  int freeListHead;     
} Mem;

void initMem(Mem*);
int newNode(Mem*, double);
void freeNode(Mem*, int);
void inorder(Mem*, int);
int insert(Mem*, int, double);
int minValueNode(Mem*, int);
int deleteNode(Mem*, int, double);

#endif

