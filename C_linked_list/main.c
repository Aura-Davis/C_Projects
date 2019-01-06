#include <stdio.h>
#include <stdlib.h>

//Define Node
struct Node
{
    int data;
    struct Node* next;
};

//Node constructor
struct Node * init_node (int data)
{
    //Dynamically create a new node. Set data to passed value, and set next to null, and return it
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

//insert new node to the end of the list
void insert_back (struct Node ** head_ref, int data)
{
    struct Node * temp = (*head_ref);
    //If there is no head node create a new node with value data and make it the head node
    if(*head_ref == NULL) (*head_ref) = init_node(data);
    //traverse to the end of the list and insert a new node with value data
    else
    {
        while(temp->next != NULL) temp = temp->next;
        temp->next = init_node(data);
    }
}

//Insert the given data into a new node after the given prev_node
void insert_after (struct Node ** prev_node, int data)
{
    //Create a new node with given data
    struct Node * temp = init_node(data);
    //set the next pointer of the new node to the node pointed to by prev_node
    temp->next = (*prev_node)->next;
    //set prev_node next pointer to new node
    (*prev_node)->next = temp;
}

//Delete a node at the given position
void delete_node (struct Node ** head_ref, int position)
{
    struct Node* temp = (*head_ref);
    struct Node* next;
    //If list is empty print message and exit function
    if (*head_ref == NULL)
    {
        printf("empty list\n");
        return;
    }

    //Traverse the list until you get to the given position
    for (int i = 0;temp->next != NULL && i < (position - 1); i++)
    {
        temp = temp->next;
    }
    //If position is empty exit function
    if (temp->next == NULL) return;

    //Set next node to node after the node to be deleted
    next = temp->next->next;
    //Delete the node at the given position
    free(temp->next);
    //Set the next pointer of the node before the node to be deleted to the node after the node to be deleted
    temp->next = next;
}

//Print list from front to back
void print_list(struct Node * head)
{
    struct Node * temp = head;
    //traverse list printing data until NULL
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node * head = NULL;
    delete_node(&head, 6);
    insert_back(&head, 5);
    insert_back(&head, 5);
    insert_back(&head, 7);
    insert_after(&head->next, 8);
    print_list(head);
    delete_node(&head, 6);
    int a;
    printf("Given number to insert: ");
    scanf("%d", &a);
    insert_back(&head, a);
    print_list(head);

    return 0;
}
