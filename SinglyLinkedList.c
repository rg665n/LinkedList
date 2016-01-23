#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct ListNode{
    int data;
    struct ListNode *next;
} Node;

/* Create new Node */
Node* newNode(int value) {
    Node* newNd;
    newNd= (Node*)malloc(sizeof(Node));
    if(newNd == NULL) {
        printf("Memory Not allocated \n");
        exit(EXIT_FAILURE);
    }
    newNd->data = value;
    newNd->next = NULL;
    return newNd;
}

/*Get Data Value*/
int getVal() {
    int val;
    printf("\n Enter Value for New Node: ");
    scanf("%d",&val);
    return val;
}

void addFirst(int val , Node** head){
    printf("Node creating");
    Node *nwNd;
    nwNd =newNode(val);
    nwNd->next = *head;
    *head = nwNd;
    printf("Node created");
}

void addAtPos(int val , Node** head , int pos){
    printf("Node creating");
    if(*head == NULL) {
        printf("Linked List Does not exists");
        exit(EXIT_FAILURE);
    }
    int k=1;
    Node *nwNd;
    nwNd =newNode(val);

    Node *ptr;
    ptr = *head;
    while(  k<pos-1){
        if(ptr == NULL){
            printf("No such node exists");
            exit(EXIT_FAILURE);
        }
        ptr = ptr->next;
        k++;
    }
    nwNd->next = ptr->next;
    ptr->next = nwNd;

    printf("Node created");
}

void addLast(int val , Node** head){
    printf("Node creating");
    Node *nwNd;
    nwNd =newNode(val);
    if (*head == NULL) {
    *head = nwNd;
    }
    else {
        Node *ptr;
        ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = nwNd;
    }
    printf("Node created");
}

void delFirst(Node** head){
    printf("Node deleting");
    Node *temp;
    temp = *head;
    *head = temp->next;
    free(temp);
    printf("Node deleted");
}

void delPos(Node** head , int pos){
    printf("Node deleting");
    int k;
    Node *ptr , *q,*temp;
    ptr = *head;
    k=1;
    while(k<pos){
            k++;
            q=ptr;
            ptr = ptr->next;
    }
    q->next = ptr->next;
    free(ptr);

    printf("Node deleted");
}

void delLast(Node** head){
    printf("Node deleting");
    Node *ptr , *q,*temp;
    ptr = *head;
    while(ptr->next != NULL){
            q=ptr;
            ptr = ptr->next;
    }
    q->next = NULL;
    free(ptr);

    printf("Node deleted");
}



int getCount(Node* head){
    int cnt=0;
    Node* ptr;
    ptr = head;
    while(ptr != NULL) {
        cnt++;
        ptr = ptr->next;
    }
    printf("Return count");
    return cnt;
}
void traverse(Node* head){
    Node* ptr;
    ptr = head;
    while(ptr != NULL) {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
}

void printNthFromLast(Node* head, int Nth) {
    int len=0,fs,i;
    Node* ptr;
    ptr = head;
    while(ptr != NULL) {
        len++;
        ptr = ptr->next;
    }
    if(Nth > len) {
        printf("No such node exists");
        exit(EXIT_FAILURE);
    }
    fs = len-Nth+1;
    printf("\nfs = %d th element from start ",fs);
    ptr = head;
    for(i=1 ; i<fs; i++) {
        ptr = ptr->next;
        //printf("\ni=%d",i);
        //printf("\t data=%d",ptr->data);
    }
    printf("Item at %d position = %d " ,Nth,ptr->data);

}

void printNthFromLast_m2( Node* head, int n)
{
   Node *main_ptr = head;
   Node *ref_ptr = head;

  int count = 0;
  if(head != NULL)
  {
     while( count < n )
     {
        if(ref_ptr == NULL)
        {
           printf("%d is greater than the no. of "
                    "nodes in list", n);
           return;
        }
        ref_ptr = ref_ptr->next;
        count++;
     } /* End of while*/

     while(ref_ptr != NULL)
     {
        main_ptr = main_ptr->next;
        ref_ptr  = ref_ptr->next;
     }
     printf("Node no. %d from last is %d ",
              n, main_ptr->data);
  }
}

/* Insert node in Sorted Linked List */

void addinSorted(int val , Node** head){
    printf("Node creating");
    /* Create New Node */
    Node *ptr, *prv;
    Node *nwNd;
    ptr = *head;
    nwNd =newNode(val);
    while(ptr != NULL && ptr->data < nwNd->data) {
        prv=ptr;
        ptr=ptr->next;
    }
    nwNd->next = prv->next;
    prv->next = nwNd;

    printf("Node created");
}

void reverse(Node** head) {

    Node *temp =NULL;
    Node *nextNode =NULL;
    while((*head)) {
        nextNode = (*head)->next;
        (*head)->next = temp;
        temp=(*head);
        (*head) = nextNode;
    }
    (*head) = temp;
    printf("\n\n Linked list reverse.Choose 2 to see linked list \n\n ");
}

void recursiveReverse(Node** head)
{
    Node* first;
    Node* rest;

    /* empty list */
    if (*head == NULL)
       return;

    /* Split list into two first part contains first element only
    while other part will have rest of the elements*/
    first = *head;
    rest  = first->next;

    /* When rest List has only one node */
    if (rest == NULL)
       return;

    /* reverse the rest list */
    recursiveReverse(&rest);
    /*put the first element at the end */
    first->next->next  = first;

    /* As first is at end make its next as NULL */
    first->next  = NULL;

    /* Update head as start of rest list */
    *head = rest;
}

int main(){
    int ch,loc;
     Node *p = NULL;
     while(ch!=4)
      {
      system("cls");
      printf("------------------------");
      printf("\n1.Add First");
      printf("\n2.Display Link List");
      printf("\n3.Display no. of nodes");
      printf("\n4.Exit");
      printf("\n5.Add Last");
      printf("\n6.Add at LOC");
      printf("\n7.Delete First");
      printf("\n8.Delete Last");
      printf("\n9.Delete at LOC");
      printf("\n10.Find Nth Element from Last ");
      printf("\n11.Find Nth Element from Last for Method 2");
      printf("\n12.Insert node in Sorted Linked List");
      printf("\n13.Reverse linked List : Iterative Method");
      printf("\n14.Reverse linked List : Recursive Method");
      printf("\nEnter your choice: ");
      scanf("%d",&ch);
      switch(ch)
        {
        case 1: //Adding Nodes
            addFirst(getVal(),&p);
            break;
        case 2:
            printf("Display the Link list");
            traverse(p);
            break;
        case 3:
            printf("Number of nodes in linked list are : %d", getCount(p));
            break;
        case 4:
            exit(1);
            break;
        case 5:
            addLast(getVal(),&p);
            break;
        case 6:
            printf("Enter position to enter value");
            scanf("%d",&loc);
            addAtPos(getVal(),&p,loc);
            break;
        case 7:
            delFirst(&p);
            break;
        case 8:
            delLast(&p);
            break;
        case 9:
            printf("Enter position to enter value");
            scanf("%d",&loc);
            delPos(&p,loc);
            break;

        // Applications or puzzle  of Linked Lists
        case 10:
            printf("Enter element no from end of LL : ");
            scanf("%d",&loc);
            if(loc <=0)
                {printf("Enter a valid location");}
            else
                {printNthFromLast(p,loc);}
            break;

        case 11:
            printf("Enter element no from end of LL : ");
            scanf("%d",&loc);
            if(loc <=0)
                {printf("Enter a valid location");}
            else
                {printNthFromLast_m2(p,loc);}
            break;

        case 12: //Add in Sorted
            addinSorted(getVal(),&p);
            break;

        case 13: //Reverse LL Iterative
            reverse(&p);
            break;

        case 14: //Revers LL Recursive
            recursiveReverse(&p);
            break;
        default:
            printf("Enter a valid choice");
        }
        getch();
       }
return 0;
}
