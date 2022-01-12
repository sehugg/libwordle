libwordle
=====

[Open this project in 8bitworkshop](http://8bitworkshop.com/redir.html?platform=c64&githubURL=https%3A%2F%2Fgithub.com%2Fsehugg%2Flibwordle&file=libwordle.c).

This is a C library for making Wordle-like games for 8-bit systems.

Platforms supported:

* C64 (cc65)

## Example

```c
#include "libwordle.h"

void play(void) {
  Wordle w;
  char buf[6];
  int iter = 1;
  int i;

  libwordle_initindex(&w, ((unsigned int)rand()) % NUMWORDS);
  printf("Word is: %s\n", w.target);
  do {
    printf("\nGuess %d: ", iter);
    gets(buf);
    for (i=0; i<5; i++) {
      buf[i] = toupper(buf[i]);
    }
    test_guess(buf);
  } while (++iter <= 7);
}
```
