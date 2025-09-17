#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* start = NULL;
struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
}
void insertAtBeginning(int value) {
    struct node *newNode = createNode(value);
    newNode->link = start;
    start = newNode;
}
void insertAtEnd(int value) {
    struct node *newNode = createNode(value);
    if (start == NULL) {
        start = newNode;
        return;
    }
    struct node *temp = start;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = newNode;
}
void insertFirstElement(int value) {
    if (start != NULL) {
        printf("List already has elements!.\n");
        return;
    }
    start = createNode(value);
}
void insertAfter(int after, int value) {
    struct node *temp = start;
    while (temp != NULL && temp->data != after)
        temp = temp->link;
    if (temp == NULL) {
        printf("Element %d not found!\n", after);
        return;
    }
    struct node *newNode = createNode(value);
    newNode->link = temp->link;
    temp->link = newNode;
}
void insertBefore(int before, int value) {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (start->data == before) { 
        insertAtBeginning(value);
        return;
    }
    struct node *temp = start;
    while (temp->link != NULL && temp->link->data != before)
        temp = temp->link;
    if (temp->link == NULL) {
        printf("Element %d not found!\n", before);
        return;
    }
    struct node *newNode = createNode(value);
    newNode->link = temp->link;
    temp->link = newNode;
}

void insertBetween(int x, int y, int value) {
    struct node *temp = start;
    while (temp != NULL && temp->data != x)
        temp = temp->link;
    if (temp == NULL || temp->link == NULL || temp->link->data != y) {
        printf("Elements %d and %d not found consecutively!\n", x, y);
        return;
    }
    struct node *newNode = createNode(value);
    newNode->link = temp->link;
    temp->link = newNode;
}
void display() {
    struct node *temp = start;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
int main() {
    int choice, val, a, b;
    do {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert 1st element\n");
        printf("4. Insert after a given element\n");
        printf("5. Insert before a given element\n");
        printf("6. Insert in between two elements\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFirstElement(val);
                break;
            case 4:
                printf("Enter element after which to insert: ");
                scanf("%d", &a);
                printf("Enter value: ");
                scanf("%d", &val);
                insertAfter(a, val);
                break;
            case 5:
                printf("Enter element before which to insert: ");
                scanf("%d", &a);
                printf("Enter value: ");
                scanf("%d", &val);
                insertBefore(a, val);
                break;
            case 6:
                printf("Enter two consecutive elements (x y): ");
                scanf("%d %d", &a, &b);
                printf("Enter value: ");
                scanf("%d", &val);
                insertBetween(a, b, val);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 8);

    return 0;
}
