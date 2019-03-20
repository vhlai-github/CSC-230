// Dynamically allocate a 2D array that holds the same set of strings as
// the command line arguments.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArguments( int rows, int cols, char args[][ cols ] )
{
  // Each row of the args array contains a string.  Print out each of the
  // strings.

  for (int j = 0; j <rows; j++){
        for(int k = 0; k<=cols; k++){
            if(args[j][k] == '\0'){
                break;
            }
            printf("%c", args[j][k]);
        }
        putchar('\n');
  }
}

int main( int argc, char *argv[] )
{
  // Figure out the length of the longest command-line argument.
  int longest = 0;

  for (int j = 0; j < argc; j++){
      int size = 0;
      while(argv[j][size]!='\0'){
          size++;
      }
      if (size > longest){
          longest = size;
      }
  }

  // Dynamically allocate a 2D array of characers, with one row for every
  // command-line argument and (exactly) enough columns to hold a copy of the
  // widest command-line argument (including the null terminator at the end).
  char (*words)[ longest + 1 ];

  words = (char(*)[longest+1])malloc(argc*(longest+1)*sizeof(char));

  // Copy each command-line argumetn to a row of this new array.
  
  for (int j = 0; j < argc; j++){
        for(int k = 0; k <=(longest+1); k++){
            if(argv[j][k] == '\0'){
                break;
            }
            words[j][k] = argv[j][k];
        }
  }

  // Call a function that's expecting the command-line arguments as a 2D array
  // (not as an array of pointers).
  printArguments( argc, longest + 1, words );

  return 0;
}
