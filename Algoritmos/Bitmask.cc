#include <bits/stdc++.h>
using namespace std;
/*
  Some operations in Bits, that handle bitmasks!.
 */
int bitMask;

int substraction(int a , int b )
{
  return a & ~b;
}

int setNegation(int a)
{
  int allset = INT_MAX; // Depending on the datatype(int,long)
  return allset ^ a;
}

void setBit(int &a,int i)
{
  a |=(1 << (i-1));
}

void clearBit(int &a, int i)
{
  a &= ~(1<<(i-1));
}

bool testBit(int a,int i)
{
  return ((a & 1 << (i-1)) != 0);
}

void iterateSubmask(int m)
{
  for(int s = m ; s ; s = (m&(s-1)))
    {
    }
}

void iterateAllSubmasks(int n)
{
  for(int m = 0 ; m < (1<<n); ++m)
    {
      for(int s = m ; s ; s = (m&(s-1)))
      {
	
      }
    }
}

int main()
{
  int numero = 200123;
  int numero2 = 2031;
  bitset<32> bitis(numero);
  bitset<32> bitus(numero2);
  cout << bitis << "\n";
  cout << bitus << "\n";
  // cout << numero << "\n";
  // cout << testBit(numero,2) << "\n";
  bitset<32> bitos(substraction(numero,numero2));
  cout << bitos << "\n";
  return 0;
}
