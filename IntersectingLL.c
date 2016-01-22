#include<stdio.h>
#include<stdlib.h>

/* Link list node */
typedef struct node
{
  int data;
  struct node* next;
}Node;

int getIntersectingNode(Node* head1, Node* head2) {
    /* Find Length of LinkedLists L1 and L2 */
    Node *p1,*p2,*b,*s;
    int len1=0,len2=0,diff,i;
    p1=head1;
    p2=head2;
    while(p1 != NULL){
        p1=p1->next;
        len1++;
    }
    while(p2 != NULL){
        p2=p2->next;
        len2++;
    }

    /*Find diff and decide big vs small list */
    if(len1 > len2) {
        diff = len1-len2;
        b=head1;
        s=head2;
    }
    else {
        diff = len2-len1;
        s=head1;
        b=head2;
    }

    /* Move Big LL by diff nodes ahead */
    for(i=0;i<diff;i++) {
        b=b->next;
    }

    while(b!=NULL && s!=NULL) {
        if(b==s) {
            printf("Intersecting point is : %d ",b->data);
            return 1;
        }
        b=b->next;
        s=s->next;
    }
    return 0;

}

int main() {
    /*
    Create two linked lists

    1st 3->6->9->15->30
    2nd 10->15->30

    15 is the intersection point
  */

  struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;

  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

  getIntersectingNode(head1, head2);
}
