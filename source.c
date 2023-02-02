// C program to print binary tree reverse level order traversal

#include <stdio.h>
#include <stdlib.h>
// A binary tree node has data, pointer to left and right child
struct treeNode
{
    int data;
    struct treeNode *leftptr;
    struct treeNode *rightptr;
};
// Function prototypes
void reverseLevelOrder(struct treeNode *root);
struct treeNode *newNode(int data);

// it returns height of tree
int getHeight(struct treeNode *root)
{
    int leftHeight;
    int rightHeight;

    // if there is no root returns 0.
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // iterate left nodes recursively and assign it to variable.
        leftHeight = getHeight(root->leftptr);
        // iterate right nodes recursively and assign it to variable.
        rightHeight = getHeight(root->rightptr);
    }

    // return value which is higher.
    if (leftHeight >= rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

// referenced from
// "https://www.geeksforgeeks.org/print-level-order-traversal-line-line/"
//  it prints left to right at level that is taken by parameter.
void printfLeftToRightAtLevel(struct treeNode *root, int currentLevel)
{
    // if there is no root exit to the functions.
    if (root == NULL)
    {
        return;
    }
    // if level equals to 0 it means there are only root in the tree so return its data.
    else if (currentLevel == 0)
    {
        printf("%d ", root->data);
    }
    // if there are more than 1 level, print them recursively left to right.
    else
    {
        // first print left child of parent if its exist.
        printfLeftToRightAtLevel(root->leftptr, currentLevel - 1);
        // then print right child of parent if its exist.
        printfLeftToRightAtLevel(root->rightptr, currentLevel - 1);
    }
}

// Function to print reverse level order traversal a binary tree
void reverseLevelOrder(struct treeNode *root)
{
    // iterates levels start with last level(max depth) to 0 level(root).
    for (int i = getHeight(root) - 1; i >= 0; i--)
    {
        // calls function that print level that is taken as a parameter left to right.
        printfLeftToRightAtLevel(root, i);
    }
}

// Insert new node to the binary tree
struct treeNode *newNode(int data)
{
    struct treeNode *treeNode = (struct treeNode *)malloc(sizeof(struct treeNode));
    treeNode->data = data;
    treeNode->leftptr = NULL;
    treeNode->rightptr = NULL;
    return (treeNode);
}
int main()
{
    struct treeNode *root = newNode(9);
    root->leftptr = newNode(12);
    root->rightptr = newNode(21);
    root->leftptr->leftptr = newNode(15);
    root->leftptr->rightptr = newNode(8);
    root->rightptr->leftptr = newNode(7);
    root->rightptr->rightptr = newNode(11);

    printf("Level Order traversal of binary tree is \n");
    reverseLevelOrder(root);
    return 0;
}