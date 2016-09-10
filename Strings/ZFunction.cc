#include <bits/stdc++.h>
using namespace std;

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
