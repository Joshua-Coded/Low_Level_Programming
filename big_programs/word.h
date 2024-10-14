#ifndef WORD_H
#define WORD_H

/*************************************************************************
* read_word: Read the next word from the input and                       *
*            Stores it in word. Makes word empty if no                   *
*            word could be read because of end-of-line.                  *
*            Truncate the word if its lenght exceeds                     *
*            len.                                                        *
*************************************************************************/

void read_word(char *word, int len);

#endif
