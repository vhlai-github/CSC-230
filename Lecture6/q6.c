#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    
    goto inside;

for ( int i = 10; i > 0; i-- ) {
    for ( int j = 10; j > 0; j-- ) {
inside:
      printf( "%d - %d\n", i, j );
    }
  }

}