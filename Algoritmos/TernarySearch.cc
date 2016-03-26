#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
  return x*x;
}

//Funcion f(x), con dominio [A,B].
double ternarysearch(double A,double B,double x)
{
  double left  = A , right  = B,ans = -1;
  int count = 500;
  while(count--) // while(abs(m1 - m2) < 1e-10) osea algo muy peque;o pero esta condicion es mas peligrosa
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
