
#ifndef _LIBWORDLE_H
#define _LIBWORDLE_H

#define LETTER(ch) ((ch)-'A')

#define GUESS_GREY   0
#define GUESS_YELLOW 1
#define GUESS_GREEN  2

#define NUMWORDS 8938

// structure that holds information
// for a single guess
// - the target word
// - status of each of the 5 letters
//   (0=grey, 1=yellow, 2=green)
// - bitmask for each of the 26 letters
//   (+1=grey, +2=yellow, +4=green)
typedef struct Wordle {
  char target[5];	// target word
  char zero;
  uint8_t guesses[5];	// result of each letter
  uint8_t status[26];	// persistent result from A-Z
} Wordle;

// is this word valid?
// i.e. 5 uppercase letters and in the dictionary
// return 1 if valid word, 0 if not
char libwordle_isvalid(const char* word);

// init structure with a target word
void libwordle_init(Wordle* state, const char* target);

// init structure with a word at a given index
// (0 to NUMWORDS-1)
// return 1 if valid index, 0 if not
char libwordle_initindex(Wordle* state, int targetIndex);

// update structure with a single guess
// return 1 if valid guess, 0 if not
// return 2 if we won the game!
char libwordle_update(Wordle* state, const char* guess);

#endif
