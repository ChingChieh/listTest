#include <assert.h>
#include "list.h"

int main()
{
    char *a_str = "andf";
    char *b_str = "bitc";
    char *c_str = "catt";
    char *d_str = "dabc";
    char *e_str = "eeei";

    char *test1 = "dab2";
    
    record *head = NULL;
    
    insert_sorted(&head, a_str);
    insert_sorted(&head, b_str);
    insert_sorted(&head, c_str);
    insert_sorted(&head, d_str);
    insert_sorted(&head, e_str);
    assert(head != NULL);

    delete_sorted(&head, b_str);
    delete_sorted(&head, e_str);
    assert(head->next->next->next == NULL);
    assert(head->next->next != NULL);
    delete_sorted(&head, test1);
    assert(head->next->next->next == NULL);
    assert(head->next->next != NULL);
    delete_sorted(&head, c_str);
    delete_sorted(&head, a_str);
    delete_sorted(&head, d_str);
    assert(head == NULL);
    delete_sorted(&head, d_str);
    assert(head == NULL);

    return 0;
}
