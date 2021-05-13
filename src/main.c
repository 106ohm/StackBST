#include <BinarySearchTreeStack.h>
 
// Driver Code
int main()
{
  /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

  Mem* mem = initMem();
  int root = -1;

  root = insert(mem, root, 50);
  root = insert(mem, root, 30);
  root = insert(mem, root, 20);
  root = insert(mem, root, 40);
  root = insert(mem, root, 70);
  root = insert(mem, root, 60);
  root = insert(mem, root, 80);

  printf("Inorder traversal of the given tree \n");
  inorder(mem, root);
  
  printf("\nDelete 20\n");
  root = deleteNode(mem, root, 20);
  printf("Inorder traversal of the modified tree \n");
  inorder(mem, root);
  
  printf("\nDelete 30\n");
  root = deleteNode(mem, root, 30);
  printf("Inorder traversal of the modified tree \n");
  inorder(mem, root);
  
  printf("\nDelete 50\n");
  root = deleteNode(mem, root, 50);
  printf("Inorder traversal of the modified tree \n");
  inorder(mem, root);
  
  return 0;
}
