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

void deleteNODE(record **node, const char *value){                                                                                
    while((*node)->next){
        if(!strcmp(value,(*node)->next->value)){
            record *delete = (*node)->next;
            (*node)->next = (*node)->next->next;
            free(delete);
            break;
        }   
        node = &((*node)->next);
    }   
}

record* searchNODE(record *node, const char *value){
    while(node){
        if(!strcmp(value,node->value)){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

