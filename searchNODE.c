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

    record a;
    record b;
    record c;
    record d;

    a.value = malloc(5);
    strcpy(a.value, a_str);
    b.value = malloc(5);
    strcpy(b.value, b_str);
    c.value = malloc(5);
    strcpy(c.value, c_str);
    d.value = malloc(5);
    strcpy(d.value, d_str);

    
    record *head;
    head = malloc(sizeof(record));
    head->next = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;


    record *get_node1 = searchNODE(head->next, test1);
    assert(strcmp(get_node1->value, test1) == 0);
    record *get_node2 = searchNODE(head->next, test2);
    assert(get_node2 == NULL);

    return 0;
}

