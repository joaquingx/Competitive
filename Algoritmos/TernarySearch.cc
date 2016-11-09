#include <bits/stdc++.h>
using namespace std;

/*
  Finds the max or min of a function (discrete or continuos)
  TernarySearch:
  Params:
  A <- Left Border.
  B <- Right Border.
  x <- Key.
  Needs:
  Unimodal,Convex Function!.
 */

double f(double x)
{
  return x*x;
}

//f(x) Function, domain [A,B].
double ternarysearch(double A,double B,double x)
{
  double left  = A , right  = B,ans = -1;
  int count = 500; // Number of iterations!
  while(count--) // while(abs(m1 - m2) < 1e-10) <- Dangerous Condition because possible no convergence.
    {
      double m1 = left + (right-left)/3;
      double m2 = right - (right-left)/3;
      double vm1 = f(m1) , vm2 = f(m2);
      if(vm1 > vm2) // We want the max value
	{
	  right = m2;
	  ans = max(vm1,ans);
	}
      else
	{
	  left = m1;
	  ans = max(vm2,ans);
	}
    }
  return ans;
}


int main()
{
  
}
