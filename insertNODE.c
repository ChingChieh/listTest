#include "list.h"
#include <assert.h>
#include <stdio.h>

int main() {

  record *head;
  head = (record *)malloc(sizeof(record));

  record *node1;
  node1 = (record *)malloc(sizeof(record));
  node1->value = "agsfgsfdg";
  head->next = node1;

  record *node2;
  node2 = (record *)malloc(sizeof(record));
  node2->value = "bggininder";
  node1->next = node2;
  node2->next = NULL;

  insert_sorted(&(head->next), "cccchaha");

  int i = 'a';
  record *iterator = head->next;
  while (iterator) {
    assert(i == (iterator->value)[0]);
    iterator = iterator->next;
    i++;
  }
  iterator = head->next;
  record *iter_next;
  while (iterator) {
    iter_next = iterator->next;
    free(iterator);
    iterator = iter_next;
  }
  head->next = NULL;
  insert_sorted(&(head->next), "haha");
  assert(!strcmp(head->next->value, "haha"));
  return 0;
}
