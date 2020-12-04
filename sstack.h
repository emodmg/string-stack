
// This is a module that provides a stack of strings [sstack] ADT
// where each string is dynamically allocated (copied) when pushed

// all sstack parameters must be valid (non-null)

// times: n is the length of the stack (number of items)
//        m is the length of the string (parameter)

#include <stdbool.h>

struct sstack;

// sstack_create() creates a new empty string stack [sstack]
// effects: allocates memory (client must call sstack_destroy)
// time: O(1)
struct sstack *sstack_create(void);

// sstack_is_empty(ss) determines if ss is empty
// time: O(1)
bool sstack_is_empty(const struct sstack *ss);

// sstack_top(ss) returns a (const) pointer the top item in ss
// note: does not make a copy of the string
// requires: ss is not empty
// time: O(1)
const char *sstack_top(const struct sstack *ss);

// sstack_pop(ss) returns and pops (removes) the top item in stack ss
// note: caller must free the returned string
// requires: ss is not empty
// effects: modifies ss
// time: O(1)
char *sstack_pop(struct sstack *ss);

// sstack_push(str, ss) pushes str on top of ss
// note: makes a 'copy' of str (caller must free when popped)
// requires: str is a valid (non-null) string
// effects: modifies ss
//          allocates memory (caller must free when popped)
// time: O(m) [amortized]
void sstack_push(const char *str, struct sstack *ss);

// stack_destroy(ss) frees all memory for ss (including any strings)
// effects: ss is no longer valid
// time: O(n)
void sstack_destroy(struct sstack *ss);
