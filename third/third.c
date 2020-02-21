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

  //printf("Converted binary: ");
  for(i=0; i<SHORT_SIZE; i++)
  {
      //printf("%d", bin[i]);
      if(bin[i] != bin[SHORT_SIZE-i-1])
      {
        printf("%s","Not-Palindrome\n");
        break;
      }
      else if( i == SHORT_SIZE/2)
      {
        printf("%s","Is-Palindrome\n");
        break;
      }
  }
  return 0;
}
