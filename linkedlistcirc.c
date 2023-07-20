#include <stdio.h>
#include <stdlib.h>

void insert_at_beg();
void insert_at_loc();
void insert_at_end();
void delete_at_beg();
void display();

int ch;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

int main()
{
    printf("enter\n");

    do
    {
        // printf("enter the choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_at_beg();
            break;
        case 2:
            insert_at_loc();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            delete_at_beg();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("enter again");
            break;
        }
    } while (ch != 8);
    return 0;
}

void insert_at_beg()
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    // printf("enter the data");
    scanf("%d", &val);
    ptr->data = val;
    if (head == NULL)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

void insert_at_loc()
{
    int val, pos;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    scanf("%d", &pos);
    scanf("%d", &val);
    ptr->data = val;
    for (int i = 1; i < pos; i++)
    {
        if (i == 1)
        {
            temp = head;
        }
        else
        {
            temp = temp->next;
        }
    }
    ptr->next = temp->next;
    temp->next = ptr;
}
void insert_at_end()
{

    int val;
    scanf("%d", &val);
    struct node *ptr, *temp = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    if (head != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
    }
    else
    {
        head = ptr;
        head->next = head;
    }
}

void delete_at_beg()
{
    struct node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
}
void display()
{
    struct node *temp = head;
    while (temp != head)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}