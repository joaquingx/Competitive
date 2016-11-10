#include <bits/stdc++.h>
using namespace std;
/*
  The Z-function for this string is an array of length nn where the i-th element is equal
  to the greatest number of characters starting from the position i that coincide with 
  the first characters of s.
  Complexity(O(n)) using Two Pointers approach.
  Z Function:
  Z(p): p is the string that we want the borders.
  
  Example:
  idx 0 1 2 3 4 5 6 
  en a b a c a b a 
  es 0 0 1 0 3 0 1
                |
		v
  0 1 2(prefijo) con 4 5 6(sufijo) coinciden
  a b a              a b a 

  more info : http://e-maxx-eng.appspot.com/string/z-function.html
*/


vector<int> Z (string &p)
{
  vector<int> Z(p.size()); Z[0] = 0;
  for(int i = 1, l  = 0 , r = 0 ; i < p.size(); ++i)
    {
      if(i <= r)
	Z[i] = min(r-i+1 , Z[i-l]);
      while( Z[i] < p.size() && p[Z[i]] == p[i+Z[i]] )
	++Z[i];
      if(i+Z[i]-1 > r)
	l = i , r = i+Z[i]-1;
    }
  return Z;
}

int main()
{
  string pat; cin >> pat;
  vector<int> ans = Z(pat);
  for(int i = 0 ; i < ans.size() ; ++i)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
