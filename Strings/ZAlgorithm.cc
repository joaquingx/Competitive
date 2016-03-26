#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> z; // aca van los prefijos que coinciden con los sufijos.

//idx 0 1 2 3 4 5 6 
// en a b a c a b a 
// es 0 0 1 0 3 0 1
//            |
//            v
// 0 1 2(prefijo) con 4 5 6(sufijo) coinciden
// a b a              a b a 

void z_function ( string s )
{
  int l,r,n = (int)s.size();
  z.resize(n);
  for ( int i = 1 , l = 0 , r = 0 ; i < n ; ++ i ) {
    if ( i <= r )
      z[i] = min ( r - i + 1 , z[i - l] ) ;
    while ( i + z [i] < n && s[z[i]] == s[i+z[i]] )
      ++ z [i] ;
    if ( i + z [i] - 1 > r )
      l = i,  r = i + z [i] - 1 ;
  }
}

int main()
{
  string pat; cin >> pat;
  z.resize(pat.size());
  z_function(pat);
  for(int i = 0 ;i < z.size() ; ++i)
    cout << z[i] << " " ;
  cout << "\n";
  return 0;
}
