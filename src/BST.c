#include <BinarySearchTreeStack.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void initMem(Mem *mem)
{
  for (int i=0; i<N-1; i++){
    mem->key[i] = mem->left[i] = mem->right[i] = -1;
    mem->nextInFreeList[i] = i+1;
  }
  mem->key[N-1] = mem->left[N-1] = mem->right[N-1] = mem->nextInFreeList[N-1] = -1;
  mem->freeListHead = 0;
  return mem; 
}

// A utility function to create a new BST node
int newNode(Mem *mem, double item)
{
  int head = mem->freeListHead;
  if (mem->nextInFreeList[head] == -1) {
    errno = EADDRNOTAVAIL;
    perror("ERROR in newNode");
    return errno;
  }
  mem->freeListHead = mem->nextInFreeList[head];
  mem->nextInFreeList[head] = -1;
  mem->key[head] = item;
  return head;
}

void freeNode(Mem *mem, int nodeID)
{
  int head = mem->freeListHead;
  mem->nextInFreeList[nodeID] = head;
  mem->freeListHead = nodeID;
}
 
// A utility function to do inorder traversal of BST
void inorder(Mem *mem, int root)
{
  if (root != -1) {
    inorder(mem, mem->left[root]);
    printf("%f ", mem->key[root]);
    inorder(mem, mem->right[root]);
  }
}
 
/* A utility function to
   insert a new node with given key in
 * BST */
int insert(Mem *mem, int nodeID, double key)
{
  /* If the tree is empty, return a new node */
  if (nodeID==-1)
    return newNode(mem, key);
  /* Otherwise, recur down the tree */
  if (key < mem->key[nodeID])
    mem->left[nodeID] = insert(mem, mem->left[nodeID], key);
  else
    mem->right[nodeID] = insert(mem, mem->right[nodeID], key);
  /* return the (unchanged) node pointer */
  return nodeID;
}
 
/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
int minValueNode(Mem *mem, int nodeID)
{
  int current = nodeID;
  while(current>-1 && mem->left[current]>-1)
    current = mem->left[current];

  return current;
}
 
/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
int deleteNode(Mem *mem, int root, double key)
{
  // base case
  if (root == -1)
    return root;
  
  // If the key to be deleted
  // is smaller than the root's
  // key, then it lies in left subtree
  if (key < mem->key[root])
    mem->left[root] = deleteNode(mem, mem->left[root], key);
  
  // If the key to be deleted
  // is greater than the root's
  // key, then it lies in right subtree
  else if (key > mem->key[root])
    mem->right[root] = deleteNode(mem, mem->right[root], key);
 
  // if key is same as root's key,
  // then This is the node
  // to be deleted
  else {
    // node with only one child or no child
    if (mem->left[root] == -1) {
      int temp = mem->right[root];
      freeNode(mem, root);
      return temp;
    }
    else if (mem->right[root] == -1) {
      int temp = mem->left[root];
      freeNode(mem, root);
      return temp;
    }
 
    // node with two children:
    // Get the _inorder successor
    // (smallest in the right subtree)
    int temp = minValueNode(mem, mem->right[root]);
 
    // Copy the inorder
    // successor's content to this node
    mem->key[root] = mem->key[temp];
 
    // Delete the _inorder successor
    mem->right[root] = deleteNode(mem,
				  mem->right[root],
				  mem->key[temp]);
  }
  return root;
}
