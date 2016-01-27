//Flyod Algo

// C program to detect loop in a linked list ,find start of loop , length of loop and remove loop
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
          (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Check if Linked list has Loop  */

int detectloop(struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
           printf("\n\nFound Loop\n");

           return 1;
        }
    }
    printf("\n\nNo Loop\n");
    return 0;
}

/*Find Start of Loop */

int findBeginOfLoop(struct node *head) {
    struct node  *slow_p = head, *fast_p = head;
    int loopExists=0;

    /* Check if Loop Exists */

    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            loopExists = 1;
            break;
        }
    }

    /* Find Start of Loop if loop Exists */

    if(loopExists) {
        slow_p = head;
        while(slow_p != fast_p) {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }
    printf("\n\nElement at start of loop = %d", slow_p->data);
    return 1;
    }
    printf("\n\nNo Loop\n");
    return 0;
}


/*Find Length of Loop */

int findLengthOfLoop(struct node *head) {
    struct node  *slow_p = head, *fast_p = head;
    int loopExists=0;
    int len = 1;

    /* Check if Loop Exists */

    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            loopExists = 1;
            break;
        }
    }

    /* Find Length of Loop if loop Exists */

    if(loopExists) {
        fast_p = fast_p->next; // Handling in case Head is start of loop and meeting point is also head
        while(slow_p != fast_p) {
            fast_p = fast_p->next;
            len++;
        }
    printf("\n\nLength of loop = %d\n\n", len);
    return 1;
    }
    printf("\n\nNo Loop\n");
    return 0;
}


/*Find and remove Loop */

int removeLoop(struct node *head) {
 struct node  *slow_p = head, *fast_p = head;
 struct node *prev = NULL;
    int loopExists=0;

    /* Check if Loop Exists */

    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            loopExists = 1;
            break;
        }
    }

    /* Find Start of Loop if loop Exists */

    if(loopExists) {
        //printf("\n\n Rishabh Loop Exists");
        slow_p = head;

       while(slow_p != fast_p) {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }

    //printf("\n\n Element at start of loop = %d", slow_p->data);
    //Remove LOOP
    prev = slow_p;
    // Handling in case Head is start of loop and meeting point is also head
    while (prev->next != slow_p) {
        prev = prev->next;
    }
    //printf("\n\nprev->data = %d" , prev->data);
    prev->next = NULL; //Making loop's first node's prev->next as null to break the loop.
    return 1;
    }
    printf("\n\nNo Loop\n");
    return 0;
}

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n\n");
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);


    /* Create a loop for testing */
    head->next->next->next->next = head;

    /*Check if Loop Exists */

    detectloop(head);

    /*Find Begin of Loop */

    findBeginOfLoop(head);

    /*Find Length of Loop */
    findLengthOfLoop(head);

    /* Remove Loop */
    //printf("\n\nRemove Loop \n\n");
    removeLoop(head);

    printf("\nLinked List after removing loop \n\n");
    printList(head);


    return 0;
}
