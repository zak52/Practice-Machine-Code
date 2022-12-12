#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

// Creates a new List struct and initializes it (the node pointers are NULL and
// the count = 0) and then returns a pointer to it.
List *list_create(void) {
  List *list = malloc(sizeof(List));
  (*list).count = 0;
  (*list).first = NULL;
  (*list).last = NULL;
  return list;
}

// Creates a new ListNode struct and initializes it (the node pointers are NULL
// and the value is set to the passed parameter) and then returns a pointer to
// it.
ListNode *list_create_node(int value) {
	ListNode *node = malloc(sizeof(ListNode));
	(*node).value = value;
	(*node).next = NULL;
	(*node).prev = NULL;
	return node;
}

// Finds a node in the list with the passed value and returns a pointer to the
// node.  If no matching node is found, returns NULL.
ListNode *list_find(List *list, int value) {
	int num = 0;
	ListNode *currentNode = list->first;
	while(num <= list->count){
		if(value == currentNode->value){
			return currentNode;
		}
		num++;
		currentNode = list->first->next;
	}
	return NULL;
}

// Inserts a node in the list after the node containing value.  If no node has
// the passed value insert at the end of the list.
void list_insert_after(List *list, ListNode *node, int value) {
	bool inserted = false;
	if ((*list).first == NULL){
		(*list).first = node;
		(*list).last = node;
		inserted = true;
	}else{
		int num = 0;
		ListNode *currentNode = (*list).first;
		while(num <= (*list).count){
			if(value == (*currentNode).value){
				(*node).prev == currentNode;
				if((*currentNode).next != NULL){
					(*node).next = currentNode->next;
					(*currentNode).next = node; 
				}
				inserted = true;
			}
			num++;
			currentNode = (*currentNode).next; 
		}
	}
	if (inserted == false){
		list->last->next = node;
		(*node).prev = (*list).last;
		(*list).last = node;
	}
	(*list).count++;
}

// Returns the count in the list structure.
int list_count(List *list) {
  return list->count;
}

// Returns the first node in the list.
ListNode *list_first(List *list) {
	if(list->first == NULL){
		return NULL;
	}
	return list->first;
}

// Returns the last node in the list.
ListNode *list_last(List *list) {
	if (list->last == NULL){
		return NULL;
	}
	return list->last;
}

// Removes the specified node from the list and frees it.  The node's value
// is saved and returned.
int list_remove_node(List *list, ListNode *node) {

}

// Removes the node with the specified value from the list and return true.  If
// a node with the value is not found in the list, return false.
bool list_remove_value(List* list, int value) {

}

// Inserts a node in the list before the node containing value.  If no node has
// the passed value insert at the beginning of the list.
void list_insert_before(List *list, ListNode *node, int value) {
  
}

// Frees any nodes in the list but leaves the list structure.
void list_clear(List *list) {
  
}

// Frees any nodes in the list and then frees the list structure.
List *list_destroy(List *list) {
  list_clear(list);
  free(list);
  return NULL;
}




