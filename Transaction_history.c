#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
 
void pop()
{
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    free(temp);
}

void showTransactions()
{
    struct node *ptr = top;
    printf("Transactions:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int choice, transaction;
    
    while(1)
    {
        printf("\n1. Enter transaction\n");
        printf("2. Show all transactions\n");
        printf("3. Delete latest transaction\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter transaction amount: ");
                scanf("%d", &transaction);
                push(transaction);
                break;
            case 2:
                showTransactions();
                break;
            case 3:
                pop();
                printf("Latest transaction deleted\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
