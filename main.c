// This is an I/O test client to test the sstack module

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "cs136-trace.h"
#include "read-str.h"

#include "sstack.h"

int main(void) {
  const int PUSH = lookup_symbol("push");
  const int POP = lookup_symbol("pop");
  const int TOP = lookup_symbol("top");
  const int IS_EMPTY = lookup_symbol("is_empty");
  
  struct sstack *ss = sstack_create();
  
  while (1) {
    int cmd = read_symbol();
    if (cmd == PUSH) {
      char *to_push = read_str();
      if (to_push == NULL) {
        break;
      }
      sstack_push(to_push, ss);
      free(to_push);
    } else if (cmd == POP) {
      char *popped = sstack_pop(ss);
      printf("pop: %s\n", popped);
      free(popped);
    } else if (cmd == TOP) {
      printf("top: %s\n", sstack_top(ss));
    } else if (cmd == IS_EMPTY) {
      if (!sstack_is_empty(ss)) {
        printf("not ");
      }
      printf("empty\n");
    } else {
      break;
    }
  }
  sstack_destroy(ss);
}
