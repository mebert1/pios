#include <stdlib.h>
#include "list.h"

char memory_block[sizeof(node_t)];
node_t* head = NULL;
node_t* current;

int list_add(int data) {

	if(head == NULL) {
		head = (node_t*) memory_block;
		current = head;
	}

	char new_mem_block[sizeof(node_t)];
	node_t* new_node = (node_t*) new_mem_block;

	new_node->value = data;
	current->next = new_node;
	current = new_node;
	
	return 0;
}

// removes last element from list
int list_remove(void) {
	node_t* prev = head;
	while(current->next != NULL) {
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	return 0;
}
	
