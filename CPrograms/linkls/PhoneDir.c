#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	struct node * next;
	char *number;
	char *name;
};


struct node* addContact(struct node *head, char* name, char* num)
{


	struct node *temp, *root;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->name = (char *)malloc(strlen(name));
	temp->number = (char *)malloc(strlen(num));

	strcpy(temp->name, name);
	strcpy(temp->number, num);
	
	if (head == NULL){
		head = temp;
		head->next = NULL;
		strcpy(temp->name, name);
		strcpy(temp->number, num);
	}
	else{
		root = head;
		while(root->next != NULL)
			root = root->next;

		temp->next = NULL;
		root->next = temp;
	}

	return head;
}

void printDirectory(struct node *head){

	struct node *root;
	int sl=0;
	root = head;
	if(head == NULL) {
		printf("\nPhone Directory is empty\n\n");
		return;
	}
	printf("============Printing Phone Directory==============\n");
	while(root != NULL){
		printf("%d. name: %s\n number: %s\n", ++sl, root->name, root->number);
		root = root->next;
	}
	printf("============Printing Phone Directory==============\n");
}

void freeLinkedList(struct node *head){

	struct node *root;

	if(head == NULL) {
		printf("\nPhone Directory is empty\n\n");
		return;
	}
	printf("============Erasing Phone Directory==============\n");
	do{
		root = head->next;
		printf(" name: %s\n number: %s\n", head->name, head->number);
		free(head->name);
		free(head->number);
		head = root;
	}while(head != NULL);
	printf("============Erased Phone Directory==============\n");

}

void deleteContact(struct node* head, char* stringValue)
{
	struct node * temp;

	while(head != NULL){
		if((strcmp(head->name, stringValue) == 0) || (strcmp(head->number, stringValue) == 0))
		{
			temp->next = head->next;
			free(head);
			free(head->name);
			free(head->number);
			return;
		}
		temp = head;
		head = head->next;
	}
	printf("\n Contact Details not found in Phone Directory\n");
}

void searchContact(struct node* head, char* stringValue)
{
	struct node * temp;

	while(head != NULL){
		if((strcmp(head->name, stringValue) == 0) || (strcmp(head->number, stringValue) == 0))
		{
			printf("%d. name: %s\n number: %s\n", ++sl, root->name, root->number);
			return;
		}
		temp = head;
		head = head->next;
	}
	printf("\n Contact Details not found in Phone Directory\n");
}


int main(){

	struct node *head= NULL;
	char name[20];
	char number[11];
	int choice;

	while(1){

		choice = 0;
		printf("\nPlease enter your option from 1-5\n");
		printf("*****************************************************\n");
		printf("1 - Add new contact in phoneDirectory\n");
		printf("2 - Print phoneDirectory\n");
		printf("3 - search for contact\n");
		printf("4 - Delete contact from phoneDirectory\n");
		printf("5 - Erase all Contacts from phoneDirectory\n");
		printf("6 - Exit from the phoneDirectory\n");
		printf("*****************************************************\n");
		printf("Please Enter your choice :");
		scanf("%d", &choice);

		switch (choice){
			case 1:
				printf("Please enter name (20 Charecters):\n");
				scanf("%999s", name);
				printf("Please Enter 10 digit mobile number:\n");
				scanf("%999s", number);

				printf("Entered \n name : %s \n number = %s \n", name, number);

				if (head == NULL) 
					head = addContact(head, name, number);
				else 
					addContact(head, name, number);
				break;

			case 2:
				printDirectory(head);
				break;

			case 3:
				if(head == NULL) {
					printf("\nlist is empty\n");
					break;
				}
				printf("Please enter name or number:");
				scanf("%999s", name);
				deleteContact(head, name);
				break;

			case 4:
				freeLinkedList(head);
				head = NULL;
				break;

			case 5:
				freeLinkedList(head);
				head = NULL;
				printf("\nReturning from the linked list program\n");
				return 1;

			default:
				printf("\nPlease enter 1-5\n");
				break;

		}
	}
}
