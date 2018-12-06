#include "list.h"
#include <assert.h>
#include <stdio.h>

int main() {
	char *a_str = "atalanta";
	char *b_str = "boston";
	char *c_str = "chicago";
	char *d_str = "detroit";
	
	char *in_str1 = "abc";
	char *in_str2 = "abcd";
	record *head = NULL;

	insert_sorted(&head, a_str);
	insert_sorted(&head, b_str);
	insert_sorted(&head, c_str);
	insert_sorted(&head, d_str);
	assert(head != NULL);

	int i = 0;
	record *iterator = head;
	while(iterator){
		assert((iterator->value)[0] == 'a' + i);
		i++;
		iterator = iterator->next;
	}
	
	insert_sorted(&head, in_str1);
	assert(!strcmp(head->value,in_str1));	
	insert_sorted(&head, in_str2);
	assert(!strcmp(head->next->value,in_str2));	

	return 0;
}
