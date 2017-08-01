//
// Created by Mu$t4f△ J4m4L on 7/10/17.
//

#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdio.h>

struct ListNode;
typedef struct ListNode {
	struct ListNode *next;
	struct ListNode *prev;
	void *value;
} ListNode;

typedef struct List {
	int count;
	ListNode *first;
	ListNode *last;
} List;

List *List_create();    // creates the main list structure.
void List_destroy(List *list);  // destroy a List and any element it might have.
void List_clear(List *list);    // A convenient function for freeing the values in each node, not the nodes.
void List_clear_destroy(List *list);    // Clears and destroy a list. It's not very efficient since it loops through them twice.

#define List_count(A) ((A)->count)  // return the number of the elements in the list, which is maintained as elements are added and removed.
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)   // return the first element of the list
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)      // return the last element of the list

void List_push(List *list, void *value);    // The first operation that demonstrates the advantage of a linked list. it adds a new element tp the end of tje list, and because that's just a couple pointers assignments.
void *List_pop(List *list); // the inverse of List_push, this takes the last element off and returns it.

void List_unshift(List *list, void *value); // add element to the front of the list very quickly
void *List_shift(List *list);   // remove the first element and return it.

void *List_remove(List *list, ListNode *node);  // this actually doing all the removal when you do List_pop or List_shift.

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL; \   // iterates over the elements in the list.
													ListNode *V = NULL; \

for(V = _node = L->S; _node != NULL, V = _node = _node->M)

#endif //lcthw_List_h
