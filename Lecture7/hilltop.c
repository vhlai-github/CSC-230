#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void readGrid( int rows, int cols, int grid[ rows ][ cols ] )
{
  // Add code to read in all the elements of grid from standard input.
  for (int a = 0; a < rows; a++){
      for (int b = 0; b < cols; b++){
          int temp=0;
          scanf(" %d", &temp);
          grid[a][b]= temp;
      }
  }
}

void printGrid(int rows, int cols, int grid[rows][cols]){
   for (int a = 0; a < rows; a++){
      for (int b = 0; b < cols; b++){
          printf("%d ", grid[a][b]);
      }
      printf("\n");
  } 
}

// Add parameters to to pass a variable-sized array to the following
// function.  It's the same as the previous function, but I want you
// to get a chance to type it in yourself.
void reportMaxima( int rows, int cols, int grid[rows][cols] )
{
  // Add code to find local maxima and print them out in row major order.
  for (int a = 0; a < rows; a++){
      for (int b = 0; b < cols; b++){
          bool isMax = 1;
          for (int x = a-1; x < a+2; x++){
              if (x != -1 && x != rows){
                  for (int y = b - 1; y < b +2; y++){
                      if (y != -1 && y != cols){
                          if (x != a || y != b){
                              if (grid[x][y] >= grid[a][b]){
                                  isMax = 0;
                              }
                          }
                      }
                  }
              }
          }
          if (isMax == 1){
              printf("%d %d\n", a, b);
          }
      }
  }
}

int main()
{
  // Add code to read in the grid size from standard input.
  int r;
  int c;
  scanf("%d %d", &r, &c);

  // Declare a variable-sized array to hold the grid.
  int hill[r][c];

  // Call readGrid() to populate the array.
  readGrid(r, c, hill);
 
  
  // Call reportMaxima() to print out all local maxima.
  reportMaxima(r, c, hill);
  
  return EXIT_SUCCESS;
}
