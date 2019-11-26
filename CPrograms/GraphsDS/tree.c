#include <stdio.h>
#include <stdlib.h>

struct node {

struct node* lft;
struct node* rgt;
int data;
};

struct node * nd;

struct node* allocateNode(int value){

	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = value;
	newNode->lft = NULL;
	newNode->rgt = NULL;
	return newNode;
}

struct node* insertLeft(struct node *root, int value) {
    root->lft = allocateNode(value);
    return root->lft;
}


struct node* insertRight(struct node *root, int value) {
    root->rgt = allocateNode(value);
    return root->rgt;
}

void PrintInorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 

    /* then recur on left sutree */
    PrintInorder(node->lft);

    /* first print data of node */
    printf("%d", node->data );

    /* now recur on right subtree */
    PrintInorder(node->rgt);
} 

void printPreorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    printf("%d", node->data ); 

    /* then recur on left sutree */
    printPreorder(node->lft);  
  
    /* now recur on right subtree */
    printPreorder(node->rgt); 
}

void printPostorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 

    /* then recur on left sutree */
    printPostorder(node->lft);  

    /* now recur on right subtree */
    printPostorder(node->rgt);

    /* first print data of node */
    printf("%d", node->data ); 
} 

void printLeafNodes(struct node *root) 
{ 
  static int noOfLeaves;
    // if node is null, return 
    if (!root) 
        return; 
      
    // if node is leaf node, print its data     
    if (!root->lft && !root->rgt) 
    { 
        printf("%d", root->data );
	noOfLeaves ++;
        // printf("%d\n", noOfLeaves );
        return; 
    } 
  
    // if left child exists, check for leaf  
    // recursively 
    if (root->lft){
       printLeafNodes(root->lft);
       noOfLeaves ++; 
    }     
     
    // if right child exists, check for leaf  
    // recursively 
    if (root->rgt){
       printLeafNodes(root->rgt);
       noOfLeaves ++;
    }

    //printf("%d\n", noOfLeaves );
}

int main(){
    struct node *root = allocateNode(1);
    root->lft = allocateNode(2);
    root->rgt = allocateNode(3);

    root->lft->lft    = allocateNode(4); 
    root->lft->rgt   = allocateNode(5); 
    root->rgt->lft    = allocateNode(6); 
    root->rgt->rgt   = allocateNode(7); 
  
//    printf("The elements of tree are:\n %d %d %d \n", root->data, root->lft->data, root->rgt->data);

//    printf("The elements of tree are:\n %d %d %d %d %d %d %d\n", root->data, root->lft->data,  root->rgt->data, root->lft->lft->data, root->lft->rgt->data, root->rgt->lft->data, root->rgt->rgt->data);
//, root->rgt->data, root->rgt->lft->data, root->rgt->rgt->data);

    printf("PreOrder tree Traversal =====\n");
    printPreorder(root);
    printf("\n");
    printf("INOrder tree Traversal =====\n");
    PrintInorder(root);
    printf("\n");
    printf("PostOrder tree Traversal =====\n");
    printPostorder(root);
    printf("\n");
    printf("Print leaf nodes =====\n");
    printLeafNodes(root);
    printf("\n");
}
