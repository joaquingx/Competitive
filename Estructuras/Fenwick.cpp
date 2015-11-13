#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

class BIT
{
private:
  int ni;
  vi treebit;
public:
  BIT(int n){treebit.assign(n+1,0);ni=n;}
  int read(int idx)
  {
    int sum = 0 ;
    while(idx > 0)
      {
	sum += treebit[idx];
	idx -= (idx & -idx);
      }
    return sum;
  }
  
  void update(int idx , int val)
  {
    while(idx <= ni)
      {
	treebit[idx] += val;
	idx += (idx & -idx);
      }  
  }
};


int main()
{
  int f[] = {0,10,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
  BIT ntree(17);
  for(int i = 1 ; i <= 17 ; i++)
    {
      ntree.update(i,f[i]);
    }
  int i = 16;
  cout <<"Indice" << i << ": " <<ntree.read(i)<<endl;
  ntree.update5,-1);
  cout <<"Indice" << i << ": " <<ntree.read(i)<<endl;
  return 0;
}
