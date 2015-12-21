#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct CLLNode{
    int data;
    struct CLLNode *next;
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
    newNd->next = newNd;
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
    Node *nwNd , *ptr;
    nwNd =newNode(val);
    if (*head == NULL) {
        *head = nwNd;
    }
    else {
        ptr = *head;
        while(ptr->next != *head) {
            ptr = ptr->next;
        }
        nwNd->next = *head;
        ptr->next = nwNd;
        *head = nwNd;
    }

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
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        ptr->next = nwNd;
        nwNd->next = *head;
    }
    printf("Node created");
}

void delFirst(Node** head){
    printf("Node deleting");
    Node *temp , *ptr;
    if (*head == NULL) {printf("\nList Empty\n"); exit(EXIT_FAILURE);}
    temp = *head;
    ptr = *head;
    while(ptr->next != *head){
            ptr = ptr->next;
    }
    ptr->next = (*head)->next;
    *head = (*head)->next;
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
    if (*head == NULL) {printf("\nList Empty\n"); exit(EXIT_FAILURE);}
    while(ptr->next != *head){
            q=ptr;
            ptr = ptr->next;
    }
    q->next = *head;
    free(ptr);

    printf("Node deleted");
}



int getCount(Node* head){
    int cnt=0;
    Node* ptr;
    ptr = head;
    if (head == NULL) return 0;
    do {
        cnt++;
        ptr = ptr->next;
    } while(ptr !=head);
    printf("Return count");
    return cnt;
}
void traverse(Node* head){
    Node* ptr;
    ptr = head;
    if (head == NULL) {printf("\n Empty Linked List\n");}
    do {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
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
        default:
            printf("Enter a valid choice");
        }
        getch();
       }
return 0;
}
