#include <bits/stdc++.h>
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
using namespace std;
typedef int ENTERO;
#define MAXN ENTERO(1e5+100)

ENTERO dapowa[MAXN],MOD;

ENTERO module(ENTERO a, ENTERO mod)
{
  return (a%mod + mod) % mod;
}

ENTERO xGCD(ENTERO a, ENTERO b, ENTERO &x, ENTERO &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  ENTERO x1, y1, gcd = xGCD(b, module(a,b), x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}


ENTERO oper(ENTERO a, ENTERO b)
{
  // cout << a << "y "<<  b << "\n";
  return module(module(a,MOD)+module(b,MOD),MOD);
}

void POWER(ENTERO B)
{
  dapowa[0] = 1;
  for(ENTERO i = 1 ; i < MAXN ; ++i)
    {
      dapowa[i] =  module( module(dapowa[i-1],MOD) * B, MOD);
    }
}

void init(ENTERO n, ENTERO i , ENTERO f, ENTERO * m , ENTERO * rmq)
{
  if(i+1 == f) rmq[n] = module(m[i] * dapowa[i],MOD);
  else
    {
      init(LEFT(n),i,(i+f)/2,m,rmq);
      init(RIGHT(n),(i+f)/2,f,m,rmq);
      rmq[n] = oper(rmq[LEFT(n)],rmq[RIGHT(n)]);
    }
}

void update(ENTERO n , ENTERO i , ENTERO f , ENTERO p , ENTERO v , ENTERO *m , ENTERO *rmq)
{
  if(i+1==f) rmq[n]  = m[i] = module(v * dapowa[i],MOD);
  else
    {
      if(p < (i+f)/2)
	update(LEFT(n), i, (i+f)/2, p,v,m,rmq);
      else
	update(RIGHT(n),(i+f)/2,f,p,v,m,rmq);
      rmq[n] = oper(rmq[LEFT(n)],rmq[RIGHT(n)]);
    }
}

ENTERO query(ENTERO n, ENTERO i, ENTERO f, ENTERO l, ENTERO r,ENTERO *m, ENTERO * rmq)
{
  if(l >= f || r <= i ) return 0;
  else if(i >= l && f <= r) return rmq[n];
  else
    {
      ENTERO left  = query(LEFT(n), i, (i+f)/2 , l , r , m, rmq);
      ENTERO right = query(RIGHT(n), (i+f)/2 , f , l , r , m ,rmq);
      return oper(left,right);
    }
  
}

void printst(ENTERO *rmq, ENTERO L)
{
  cout << "ST:\n";
  for(int  i = 0 ; i < 3*L; ++i )
    cout << rmq[i]<< " ";
  cout << "\n";
}


int main()
{
  ios_base::sync_with_stdio(0);
  ENTERO B,L,N,*m,*rmq;
  while(cin >> B >> MOD >> L >> N)
    {
      if(B==0 and MOD==0 and L ==0 and N == 0)break;
      POWER(B);
      m = new ENTERO[L];
      for(int i = 0 ; i < L ; ++i)
	m[i] = 0;//cambiar por 0
      rmq  =  new ENTERO[3*L];
      init(1,0,L,m,rmq);
      printst(rmq,L);
      for(int i = 0 ; i < N ; ++i)
      	{
      	  char c;
      	  ENTERO a,b;
      	  cin >> c >> a >> b;
      	  if(c == 'E')
      	    {
	      update(1,0,L,a-1,b,m,rmq);
	      printst(rmq,L);
      	    }
      	  else
	    {
	      ENTERO x,y;
	      a-=1;
	      ENTERO qsup = query(1,0,L,0,b,m,rmq);
	      ENTERO qinf = query(1,0,L,0,a,m,rmq);
	      cout << qsup << " " << qinf << "\n";
	      xGCD(dapowa[a],MOD,x,y);
	      cout << x << "\n";
	      cout << module((module(qsup - qinf,MOD)) * x,MOD) << "\n";
	    }
      	}
    }
  return 0;
}
