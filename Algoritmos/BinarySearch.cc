#include <bits/stdc++.h>
using namespace std;

int bs(int left ,int right, int key)
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
