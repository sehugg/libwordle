libwordle
=====

[Open this project in 8bitworkshop](http://8bitworkshop.com/redir.html?platform=c64&githubURL=https%3A%2F%2Fgithub.com%2Fsehugg%2Flibwordle&file=libwordle.c).

This is a C library for making Wordle-like games for 8-bit systems.

Platforms supported:

* C64 (cc65)

[Wordle](https://www.powerlanguage.co.uk/wordle/) is a game by Josh Wardle.


## Example

```c
#include "libwordle.h"

void play(void) {
  char buf[6];
  int iter = 1;
  int i, result;
  
  libwordle_initindex(&w, ((unsigned int)rand()) % NUMWORDS);
  printf("Word is: %s\n", w.target);
  do {
    printf("\nGuess %d: ", iter);
    gets(buf);
    for (i=0; i<5; i++) {
      buf[i] = toupper(buf[i]);
    }
    result = libwordle_update(&w, buf);
    if (result == 0) continue;
    if (result == 2) break;
  } while (++iter <= 7);
}
```

## Technical Info

The test program takes about 24 KB, which includes:
* 1.5 KB for the library code
* 18 KB for the dictionary

Uncomment `#define LIBWORDLE_SMALLANDSLOW` to save 4 KB but make dictionary checks really really slow.
