#include <assert.h>
#include <stdio.h>
#include "list.h"

int main()
{
    char *a_str = "andf";
    char *b_str = "bitc";
    char *c_str = "catt";
    char *d_str = "dabc";

    char *test1 = "catt";
    char *test2 = "dab2";
    
    record *head = NULL;
    
    insert_sorted(&head, a_str);
    insert_sorted(&head, b_str);
    insert_sorted(&head, c_str);
    insert_sorted(&head, d_str);


    record *get_node1 = search_sorted(head, test1);
    assert(strcmp(get_node1->value, test1) == 0);
    record *get_node2 = search_sorted(head, test2);
    assert(get_node2 == NULL);

    return 0;
}

