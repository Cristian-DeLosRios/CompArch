#include <stdlib.h>
#include <stdio.h>
#define SHORT_SIZE sizeof(short) * 8 /* Size of short in bits */


int main(int argc, char **argv)
{
  unsigned int x;
  if(argc <= 1)
  {
    return 1;
  }
  x = atoi(argv[1]);
  //rintf("Enter any number: ");
  //printf("%hd\n", x);
  int index, i;
  int bin[SHORT_SIZE];

  //printf("Enter any number: ");


  index = SHORT_SIZE - 1;

  while(index >= 0)
  {
      bin[index] = x & 1;
      index--;
      x >>= 1;
  }
  int nonPair = 0;
  int pairs = 0;

  for(i=1; i<SHORT_SIZE; i++)
  {

      if((bin[i-1] == bin[i]) && (bin[i]== 1))
      {
        pairs++;
        i++;
        continue;
      }
      else if(bin[i]== 1)
      {
        nonPair=1;
      }
  }
  if(nonPair==1)
    printf("%s\t%d\n","Odd-Parity",pairs);
  else
    printf("%s\t%d\n","Even-Parity",pairs);
  return 0;
}
