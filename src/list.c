#include <stdlib.h>
#include "list.h"

struct Node* head = NULL;
struct Node* current; 

int list_add(int data) {
	// init call to create head (Null element)
	if (head == NULL) {
		//head = (struct Node*) malloc(sizeof(struct Node));
		current = head;
	}

	struct Node* new_node = NULL; // = (struct Node*) malloc(sizeof(struct Node));
	//if(new_node == NULL) {
	//	return 1;
	//}
	new_node->value = data;
	current->next = new_node;
	current = new_node;
	
	return 0;
}
	
