#include <stdio.h>
#include <stdlib.h>

//Struct for binary tree node
struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

//Function to initialize a node with given data
struct Node * init_node (int data)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

/*Function to insert a node into a binary tree. If current node is null insert node.
If data of node is less than current node recurse with node pointed to by left.
If data of node is more than current node recurse with node pointed to by right.*/
void bst_insert (struct Node ** node, int data)
{
    if ((*node) == NULL) (*node) = init_node(data);
    else
    {
        if (data <= (*node)->data && (*node)->left != NULL) bst_insert(&(*node)->left, data);
        if (data <= (*node)->data && (*node)->left == NULL) (*node)->left = init_node(data);
        if (data > (*node)->data && (*node)->right != NULL) bst_insert(&(*node)->right, data);
        if (data > (*node)->data && (*node)->right == NULL) (*node)->right = init_node(data);
    }
}
//recurse to the left most node and return it
struct Node* min_value (struct Node * node)
{
    while (node != NULL)
    {
        node = min_value(node->left);
    }
    return node;
}


struct Node* delete_node(struct Node ** head, int data)
{
    //Search for node to delete. If node not found return null
    if ((*head) == NULL) return (*head);
    if (data < (*head)->data) (*head)->left = delete_node(&(*head)->left, data);
    if (data > (*head)->data) (*head)->right = delete_node(&(*head)->right, data);
    if (data == (*head)->data)
    {
        //If node found delete the node from the tree, and return it
        if ((*head)->left == NULL)
        {
            struct Node * temp = (*head)->right;
            free((*head));
            return temp;
        }
        else if ((*head)->right ==NULL)
        {
            struct Node* temp = (*head)->left;
            free((*head));
            return temp;
        }

        else
        {
            /*If current node has children swap current node with
            the left most node of right subtree and delete current node*/
            struct Node * temp = min_value((*head)->right);
            (*head)->data = temp->data;
            (*head)->right = delete_node(&(*head)->right, temp->data);
        }
    }
    return (*head);
}
/*If wanted data less than current node data recurse with left node.
If wanted data more than current node data recurse with right node.
If wanted data matched return node with data.
If no match return null*/
struct Node * bst_search(struct Node * head, int data)
{
    if (head == NULL) return NULL;
    else
    {
        if (head->data == data) return head;
        if (head->data > data) return bst_search(head->left, data);
        if (head->data < data) return bst_search(head->right, data);
    }

}
//Recurse to the left most node then print moving to the right most node
void in_order_print(struct Node * head)
{
    if (head != NULL)
    {
        in_order_print(head->left);
        printf("%d ", head->data);
        in_order_print(head->right);
    }
}
//Print starting at current node then move to left most node then to right most node
void pre_order_print (struct Node * head)
{
    if (head != NULL)
    {
        printf("%d ", head->data);
        pre_order_print(head->left);
        pre_order_print(head->right);
    }
}
//Recurse to the right most node then print moving to the left most node
void post_order_print (struct Node * head)
{
    if (head != NULL)
    {
        pre_order_print(head->left);
        pre_order_print(head->right);
        printf("%d ", head->data);
    }
}


int main()
{
    struct Node * head = NULL;
    bst_insert(&head, 7);
    bst_insert(&head, 2);
    bst_insert(&head, 4);
    bst_insert(&head, 37);
    bst_insert(&head, 1);
    in_order_print(head);
    printf("\n");
    delete_node(&head, 4);
    pre_order_print(head);
    printf("\n");
    post_order_print(head);
    puts("");
    struct Node * temp = bst_search(head, 37);
    printf("%d", temp->data);

    return 0;
}
