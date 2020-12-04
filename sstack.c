
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


struct sstack {
  int len;
  int maxlen;
  char **data;
};


// sstack_create() creates a new empty string stack [sstack]
// effects: allocates memory (client must call sstack_destroy)
// time: O(1)
struct sstack *sstack_create(void) {
  struct sstack *result = malloc(sizeof(struct sstack));
  result->len = 0;
  result->maxlen = 1;
  result->data = malloc(sizeof(char *) * result->maxlen);
  return result;
}

// sstack_is_empty(ss) determines if ss is empty
// time: O(1)
bool sstack_is_empty(const struct sstack *ss) {
  assert(ss);
  return (ss->len == 0);
}

// sstack_top(ss) returns a (const) pointer the top item in ss
// note: does not make a copy of the string
// requires: ss is not empty
// time: O(1)
const char *sstack_top(const struct sstack *ss) {
  assert(ss);
  return *((ss->data) + ss->len - 1);
}

// sstack_pop(ss) returns and pops (removes) the top item in stack ss
// note: caller must free the returned string
// requires: ss is not empty
// effects: modifies ss
// time: O(1)
char *sstack_pop(struct sstack *ss) {
  assert(ss);
  ss->len -= 1;
  char *result = *((ss->data) + ss->len);
  //free(*(ss->data) + ss->len);
  return result;
}

// sstack_push(str, ss) pushes str on top of ss
// note: makes a 'copy' of str (caller must free when popped)
// requires: str is a valid (non-null) string
// effects: modifies ss
//          allocates memory (caller must free when popped)
// time: O(m) [amortized]
void sstack_push(const char *str, struct sstack *ss) {
  assert(str);
  assert(ss);
  char *str_cpy = malloc(sizeof(char) * (strlen(str) + 1));
  strcpy(str_cpy, str);
  if (ss->len == ss->maxlen) {
    ss->maxlen *= 2;
    ss->data = realloc(ss->data, 
                       sizeof(char *) * ss->maxlen);
  }
  *(ss->data + ss->len) = str_cpy;
  ss->len += 1;
}

// stack_destroy(ss) frees all memory for ss (including any strings)
// effects: ss is no longer valid
// time: O(n)
void sstack_destroy(struct sstack *ss) {
  assert(ss);
  for (int i = 0; i < ss->len; i += 1) {
    free(*(ss->data + i));
  }
  free(ss->data);
  free(ss);
}
    
