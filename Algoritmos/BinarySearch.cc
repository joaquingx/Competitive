#include <bits/stdc++.h>
using namespace std;
/*
  Lower Bound gives the first index that is >= key.
  Upper Bound gives the first index that is > key.
  Binary Search is a specific case of Lower Bound :P.
  Lower Bound, Upper Bound, Binary Search:
  Params:
  A <- Left Border.
  B <- Right Border.
  x <- Key.
  Needs:
  Monotonous Function
*/


/* n is the size of the int[] array A. */
int lower_bound(int A[], int n, int c)
{
  int l = 0;
  int r = n;
  while (l < r)
    {
      int m = (l+r)/2;     /* Rounds toward zero. */
      if (A[m] < c)
	l = m+1;
      else
	r = m;
    }
  return l;
}

int upper_bound(int A[], int n, int c)
{
  int l = 0;
  int r = n;
  while (l < r)
    {
      int m = (l+r)/2;
      if (A[m] <= c)       /* Note use of < instead of <=. */
	l = m+1;
      else
	r = m;
    }
  return l;
}

int bs(int arr[],int left ,int right, int key)
{
  if(right - left > 1)
    {
      int med = (left + right)/2;
      if(arr[med] > key)
	right = med;
      else
	left = med;
    }
  return left;
}


int main()
{
  return 0;
}
