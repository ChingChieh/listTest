#include <stdlib.h>
#include <string.h>

typedef struct rec {
    char *value;
    struct rec *next;
} record;

void insert_sorted(record **r, const char *value)
{
    record *newrec = NULL;
    while (*r && strcmp(value, (*r)->value) > 0)
        r = &((*r)->next);
    newrec = malloc(sizeof(record));
    newrec->value = strdup(value);
    newrec->next = *r;
    *r = newrec;                                                                                                                                             
}

void delete_sorted(record **node, const char *value)
{                                                                                
    record *curr, *prev;

    for (curr = *node, prev = NULL;
         curr != NULL && strcmp(value, curr->value);
         prev = curr, curr = curr->next)
        ;
    if (curr == NULL)
        return;
    if (prev == NULL)
        *node = (*node)->next;
    else
        prev->next = curr->next;
    free(curr);
}

record *search_sorted(record *node, const char *value)
{    
    while (node) {
        if (!strcmp(value, node->value)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
