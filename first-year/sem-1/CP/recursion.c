#include <stdio.h>

int maxDigit(unsigned n)
{
  unsigned max = 0;
  while(n)
  {
    if(n%10 > max)
    max = n % 10;
    n = n/10;
  }
  return max;
}
int sumOfDigits(unsigned n)
{
  unsigned sum = 0;
  while(n)
  {
    sum = sum + n % 10;
    n = n/10;
  }
  return sum;
}
int recursion(unsigned x, unsigned k)
{
  unsigned md = maxDigit(x);
  unsigned s = sumOfDigits(x);
  while(k)
  {
    return recursion(x*10 + md, k-1);
  }
}
int main()
{
  printf("%d\n", recursion(572,1));
}
