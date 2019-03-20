/*
    @file stats.c
    @author(edits) Vincent H Lai (vhlai)
   Read a sequence of real numbers and report the minimum, maximum
   and average values.
 */
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
  // Figure out how many values there are.
  int n;
  scanf("%d", &n);

  // Read in the first value into val.
  double val;
  scanf("%lf", &val);

  // That first value is our tentative min and max value.
  double minValue = val, maxValue = val, total = val;

  // Get the remaining n-1 values and update minValue, maxValue and total
  // based on each one.
  for (int x = 0; x < n-1; x++){
      scanf("%lf", &val);
      total = total + val;
      if (val < minValue){
          minValue = val;
      }
      if (val > maxValue){
          maxValue = val;
      }

  }
  //calculate average
  double avg = total/n;
  
  // Report the stats.
  printf("Minimum: %8.2f\n", minValue);
  printf("Maximum: %8.2f\n", maxValue);
  printf("Average: %8.2f\n", avg);

  // Exit successfully.
  return 0;
}
