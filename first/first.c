/*
& bitwise AND The bits in the result are set to 1 if the corresponding
bits in the two operands are both 1.

| bitwise inclusive OR The bits in the result are set to 1 if at least one of
the corresponding bits in the two operands is 1.

^ bitwise exclusive OR The bits in the result are set to 1 if only one of
the corresponding bits in the two operands is 1.

<< left shift Shifts the bits of the first operand left by the number
of bits specified by the second operand.

>> right shift Shifts the bits of the first operand right by the number
of bits specified by the second operand.

~ one’s complement All 0 bits are set to 1 and 1 bits are set to 0.

Example in c:
unsigned short x = 5, y = 2, z; //in binary 5 is 101 and 2 is 10
z = x & y; //result: 0
1
z = 5 | y; //result: 7
z = 5 ^ 1; //result: 4
*/


//think about in binary form
//128 64 32 16 8 4 2 1

/*
bitwise &, and opperation sumlike down on the bits
0 0 1 0 1 0
0 0 1 1 1 1
-----------
0 0 1 0 1 0

bitwise | or op
0 0 1 0 1 0
0 0 1 1 1 1
-----------
0 0 1 1 1 1

^ xor opperator oppossite result of or

<<


>>


~
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 unsigned short x;
unsigned short get(unsigned short x, int n)
{
  unsigned short newNum;
  //leftshit x, n times and perform bitwise and
  newNum = (x >> n) & 1;
  return newNum;
}
unsigned short comp(unsigned short x, int n)
{
  unsigned short newNum;
  newNum = x ^ (1 << n);
  return newNum;
}
unsigned short set(unsigned short x, int n, int v)
{
  unsigned short newNum;
  if (v == 0)
    newNum = x & (~(1 << n));
  if(v==1)
    newNum = (1 << n) | x;
  return newNum;
}


int main(int argc, char *argv[])
{
  unsigned short n,v;
  char op[5];
  FILE *fp;


  fp = fopen(argv[1],"r");
  if(fp == NULL){
    return 0;
  }

  fscanf(fp,"%hd\n", &x); //hd = short

  while(fscanf(fp,"%s%hd\t%hd\t",&op[0],&n,&v)!=EOF)//stop at end of file, go line by line
  {
    //printf("%s\t%hd\t%hd\t",op,n,v);
    if(strcmp("get", op) == 0)
    {
      printf("%d\n",get(x,n));
      //printf("%d\n", x);
    }
    if(strcmp("comp", op) == 0)
    {
      printf("%d\n",x = comp(x,n));
    //  printf("%d\n", x);
    }
    if(strcmp("set", op) == 0)
    {
      printf("%d\n",x = set(x,n,v));
      //printf("%d\n", x);
    }
  }
  fclose(fp);
  return 0;
}
