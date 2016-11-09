#include <bits/stdc++.h>
using namespace std;
/*
  Binary Indexed Tree, Fenwick Tree:
  
  init(n): n is the capacity of the tree and is initialized to 0.
  sum(r): Query, Gives the answer of f([0,r])
  add(idx,delta): Update, In the index idx add delta.
  sum(r,l): Query, Gives the answer of f([l,r])
  init(a): Initializing the tree with a vector.

*/



struct FenwickTree {
  vector<int> bit; // binary indexed tree
  int n;

  void init(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r+1)) - 1) // saltando hacia atras entre rangos
      {
	// cout << "r : "<<r << "\n";
	ret += bit[r];
      }
    return ret;
  }
  void add(int idx, int delta) { // saltando hacia adelante(no necesariamente entre rangos!).
    for (; idx < n; idx = idx | (idx+1))
      bit[idx] += delta;
  }
  int sum(int l, int r) {
    return sum(r) - sum(l-1);
  }
  void init(vector<int> a) {
    init(a.size());
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }
};

void imprimirFenwick()
{
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0 ; i < n ; ++i)
    cin >> a[i];
  FenwickTree bitis;
  bitis.init(a);
  for(int  i = 0 ; i < n ; ++i)
    cout << bitis.bit[i] << " ";
  cout << "\n";
  cout << bitis.sum(5);
}

int main()
{

  return 0;
}






























