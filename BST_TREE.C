#include <stdio.h>
#include <stdlib.h>

// structure of a BSTree
struct BSTree
{
 int data;
 struct BSTree *lfchld;
 struct BSTree *rtchld;
};
typedef struct BSTree BSTree;

// globally initialized root pointer
struct BSTree *root = NULL;

// function prototyping
struct BSTree *create_BSTree(int);
void insert(int);
struct BSTree *delete (struct BSTree *, int);
int search(int);
void inorder(struct BSTree *);

void postorder();
void preorder();
struct BSTree *smallest_BSTree(struct BSTree *);
struct BSTree *largest_BSTree(struct BSTree *);
int get_data();

void main()
{
 int userChoice;
 int userActive = 'Y';
 int data;
 struct BSTree* result = NULL;
 clrscr();

 while (userActive == 'Y' || userActive == 'y')
 {
  printf("\n\n------- Binary Search Tree ------\n");
  printf("\n1. Insert");
  printf("\n2. Delete");
  printf("\n3. Search");
  printf("\n4. Get Larger BSTree Data");
  printf("\n5. Get smaller BSTree data");
  printf("\n\n-- Traversals --");
  printf("\n\n6. Inorder ");
  printf("\n7. PreOrder ");
  printf("\n8. PostOder ");
  printf("\n9. Exit");

  printf("\n\nEnter Your Choice: ");
  scanf("%d", &userChoice);
  printf("\n");

  switch(userChoice)
  {
   case 1:data = get_data();
	  insert(data);
	  break;

   case 2:data = get_data();
	  root = delete(root, data);
	  break;

   case 3:data = get_data();
	  if(search(data) == 1)
	  {
	   printf("\nData was found!\n");
	  }

	  else
	  {
	   printf("\nData does not found!\n");
	  }
	  break;

   case 4:result = largest_BSTree(root);
	  if(result != NULL)
	  {
	   printf("\nLargest Data: %d\n", result->data);
	  }
	  break;

   case 5:result = smallest_BSTree(root);
	  if(result != NULL)
	  {
	   printf("\nSmallest Data: %d\n", result->data);
	  }
	  break;

   case 6:inorder(root);
	  break;

   case 7:preorder(root);
	  break;

   case 8:postorder(root);
	  break;

   case 9 :exit(0);
	   break;

   default:printf("\n\tInvalid Choice\n");
	   break;
  }
  printf("\n__________\nDo you want to continue? ");
  fflush(stdin);
  scanf(" %c", &userActive);
 }
}

// creates a new BSTree
struct BSTree *create_BSTree(int data)
{
 struct BSTree *new_BSTree = (struct BSTree *)malloc(sizeof(struct BSTree));

 if(new_BSTree == NULL)
 {
  printf("\nMemory for new BSTree can't be allocated");
  return NULL;
 }

 new_BSTree->data = data;
 new_BSTree->lfchld = NULL;
 new_BSTree->rtchld = NULL;

 return new_BSTree;
}

// inserts the data in the BST
void insert(int data)
{
 struct BSTree *temp,*prev;
 struct BSTree *new_BSTree = create_BSTree(data);

 if (new_BSTree != NULL)
 {
  // if the root is empty then make a new BSTree as the root BSTree
  if (root == NULL)
  {
   root = new_BSTree;
   printf("\n* BSTree having data %d was inserted\n", data);
   return;
  }

  temp = root;
  prev = NULL;

  // traverse through the BST to get the correct position for insertion
  while (temp != NULL)
  {
   prev = temp;
   if (data > temp->data)
   {
    temp = temp->rtchld;
   }
   else
   {
    temp = temp->lfchld;
   }
  }

  // found the last BSTree where the new BSTree should insert
  if (data > prev->data)
  {
   prev->rtchld = new_BSTree;
  }
  else
  {
   prev->lfchld = new_BSTree;
  }

  printf("\n* BSTree having data %d was inserted\n", data);
 }
}

// deletes the given key BSTree from the BST
struct BSTree *delete (struct BSTree *root, int key)
{
 struct BSTree *temp;
 if (root == NULL)
 {
  return root;
 }
 if (key < root->data)

 {
  root->lfchld = delete (root->lfchld, key);
 }
 else if (key > root->data)
 {
  root->rtchld = delete (root->rtchld, key);
 }
 else
 {
  if (root->lfchld == NULL)
  {
   struct BSTree *temp = root->rtchld;
   free(root);
   return temp;
  }
  else if (root->rtchld == NULL)
  {
   struct BSTree *temp = root->lfchld;
   free(root);
   return temp;
  }
  temp = smallest_BSTree(root->rtchld);
  root->data = temp->data;
  root->rtchld = delete (root->rtchld, temp->data);
 }

 return root;

}

// search the given key BSTree in BST
int search(int key)
{
 struct BSTree *temp = root;

 while (temp != NULL)
 {
  if (key == temp->data)
  {
   return 1;
  }
  else if (key > temp->data)
  {
   temp = temp->rtchld;
  }
  else
  {
   temp = temp->lfchld;
  }
 }
 return 0;

}

// finds the BSTree with the smallest value in BST
struct BSTree *smallest_BSTree(struct BSTree *root)
{
 struct BSTree *curr = root;
 while (curr != NULL && curr->lfchld != NULL)
 {
  curr = curr->lfchld;
 }
 return curr;
}

// finds the BSTree with the largest value in BST
struct BSTree *largest_BSTree(struct BSTree *root)
{
 struct BSTree *curr = root;
 while (curr != NULL && curr->rtchld != NULL)
 {
  curr = curr->rtchld;
 }
 return curr;
}

// inorder traversal of the BST
void inorder(struct BSTree *root)
{
 if (root == NULL)
 {
  return;
 }
 inorder(root->lfchld);
 printf("%d ", root->data);
 inorder(root->rtchld);
}

// preorder traversal of the BST

void preorder(struct BSTree *root)
{
 if (root == NULL)
 {
  return;
 }
 printf("%d ", root->data);
 preorder(root->lfchld);
 preorder(root->rtchld);
}

// postorder travsersal of the BST
void postorder(struct BSTree *root)
{
 if (root == NULL)
 {
  return;
 }
 postorder(root->lfchld);
 postorder(root->rtchld);
 printf("%d ", root->data);
}

// getting data from the user
int get_data()

{
 int data;
 printf("\nEnter Data: ");
 scanf("%d", &data);
 return data;
}