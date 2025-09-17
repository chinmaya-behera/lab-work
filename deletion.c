#include <stdio.h>
#include <stdlib.h>
int i,a,b,c,choice;
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void printList() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {  
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}
void deleteOnlyNode() {
    if (head == NULL || head->next != NULL) {
        printf("List is not a single-node list.\n");
        return;
    }
    free(head);
    head = NULL;
}
void deleteAfter(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Cannot delete after node %d.\n", key);
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}
void deleteBefore(int key) {
    if (head == NULL || head->next == NULL || head->data == key) {
        printf("Cannot delete before node %d.\n", key);
        return;
    }

    struct Node *prev = NULL, *curr = head;

    while (curr->next != NULL && curr->next->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == NULL) {
        printf("Node %d not found.\n", key);
        return;
    }

    if (prev == NULL) {
    	
        head = head->next;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

void deleteAtPosition(int pos) {
    if (head == NULL || pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* temp = head;
    for ( i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}
void displayList() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
	
		
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    insertEnd(60);
    insertEnd(70);
    insertEnd(80);
    insertEnd(90);
    insertEnd(100);
    printList();
  
	while(1){

    printf(" Deletion Menu ---\n");
    printf("1. deleteAtBeginning\n");
    printf("2. deleteAtEnd\n");
    printf("3. deleteOnlyNode\n");
    printf("4. deleteAfter\n");
    printf("5. deleteBefore\n");
    printf("6. deleteAtPosition\n");
    printf("7. displayList\n");
    printf("8.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
    	case 1:
    		deleteAtBeginning();
    		break;
    	case 2:
    		deleteAtEnd();
    		break;
    	case 3:
    		deleteOnlyNode();
    		break;
    	case 4:
    		
    			printf("enter the value of node:");
    			scanf("%d",&a);
    		 deleteAfter(a);
    		break;
    	case 5:
    				
    			printf("enter the value of node:");
    			scanf("%d",&b);
    		deleteBefore(b);
    		break;
    	case 6:
    				
    			printf("enter the position of node:");
    			scanf("%d",&c);
    		deleteAtPosition(c);
    		break;
    	case 7:
    		displayList();
    		break;
    	case 8:
    			printf("exiting program");
    		exit(0);
    	default:
    			printf("invalid input\n");
    			
    			
    		
	}
	
}
return 0;
}
    
    
