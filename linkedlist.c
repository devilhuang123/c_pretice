#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node queue_node;
struct node* add(struct node *ptr,int d)
{
    struct node *current=NULL;
    current=(struct node*)malloc(sizeof(struct node*));
    ptr->next=current;
    current->data=d;
    current->next=NULL;

    return current;
}
struct node* remove_node(struct node *head,int num)
{
    struct node *temp_head=NULL;
    struct node *temp_node=NULL;

    temp_head=head;
    temp_node=head;
    int i;

    if(num==1)
    {
        temp_head=temp_node->next;
    }
    else if(num>1)
    {
        for(i=1;i<num-1;i++)
            temp_node=temp_node->next;
        temp_node->next=temp_node->next->next;
    }
    return temp_head;

}
struct node* reverse_list(struct node *head)
{
    struct node *prev_node,*current,*next_node=NULL;
    int i;

    for(i=0;head->next!=NULL;head=next_node,i++)
    {
        current=head;
        next_node=head->next;
        if(i==0)
        {
            prev_node=current;
            current->next=NULL;
        }
        else
        {
            current->next=prev_node;
            prev_node=current;
        }
    }
    head->next=current;
    return head;

}
void print_list(struct node *head)
{
    struct node *ptr=NULL;
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
        printf("%d ",ptr->data);
    printf("\n");
}
int pop(struct node **top)
{
    if((*top)->next!=NULL)
    {
        int temp_data=(*top)->data;
        *top=(*top)->next;
        return temp_data;
    }
    else
    {
        printf("stack is empty\n");
        return -1;
    }

}
struct node* push(struct node *top,int d)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node*));
    temp->next=top;
    temp->data=d;


    return temp;

}
void EnQueue(queue_node **q,int d)
{
    queue_node *current=NULL;
    current=(queue_node*)malloc(sizeof(queue_node*));
    (*q)->next=current;
    current->data=d;
    current->next=NULL;
    (*q)=current;

}
int DeQueue(queue_node **head_node)
{
   // queue_node *tempNode;

    int temp_data=(*head_node)->data;
    (*head_node)=(*head_node)->next;
    return temp_data;
}
/*
bool QueueEmpty(queue_node *front_node)
{
    if(front_node->next==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}*/
void main()
{
    queue_node *front_n,*rear_n=NULL;
    front_n=(queue_node*)malloc(sizeof(queue_node*));
    rear_n=front_n;
    front_n->data=0;
    rear_n->next=NULL;

    int i;
    for(i=1;i<=5;i++)
        EnQueue(&rear_n,i);
    print_list(front_n);
    DeQueue(&front_n);
    DeQueue(&front_n);
    DeQueue(&front_n);
    EnQueue(&rear_n,20);
    print_list(front_n);
    /*-----stack-------
    struct node *stack_bottom=NULL;
    struct node *stack_top=NULL;

    stack_bottom=(struct node*)malloc(sizeof(struct node*));
    stack_top=stack_bottom;
    stack_top->next=NULL;
    stack_top->data=0;

    //printf("%x , %x, %d\n",&stack_top,stack_top,*stack_top);
    int i;
    for(i=1;i<=5;i++)
        stack_top=push(stack_top,i);

    printf("push 1,2,3,4,5 in stack:\n");
    print_list(stack_top);
    for(i=1;i<=6;i++)
        printf("Num:%d pop=%d\n",i,pop(&stack_top));

    print_list(stack_top);*/
    /*-----linked list ----
    struct node *head=NULL;
    struct node *ptr=NULL;
    head=(struct node*)malloc(sizeof(struct node*));

    ptr=head;
    ptr->data=0;
    ptr->next=NULL;
    int i;
    for(i=1;i<=5;i++)
        ptr=add(ptr,i);

    printf("linked list data:\n");
    print_list(head);
    printf("reverse linked list:\n");
    head=reverse_list(head);
    print_list(head);
    printf("delete number 2 data from linked list:\n");
    head=remove_node(head,2);
    print_list(head);
    */
    system("pause");
}
