
#include "list.h"

int listDeleteLargest(List l) {
	Node curr = l->head;
	int max = curr->value;
	if (curr->next != NULL) {
		while (curr != NULL) {
			if (curr->value >= max) {
				max = curr->value;
			}
			curr = curr->next;
		}	
	}
	curr = l->head;
	if (curr->value == max) {
		l->head = curr->next;
		free(curr);
	} else {
		while (curr->next->value != max) {
			curr = curr->next;
		}
		Node temp = curr->next;
		curr->next = temp->next;
		free(temp);
	}

	return max;
}

