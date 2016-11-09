#include <bits/stdc++.h>
#include <math.h>
using namespace std;
/*
  Misc of Geometry Algorithms.
  Attention:
  Operator ^ is the cross product.
*/


#define PI 3.14159265
typedef double dd;

struct point
{
  dd x,y;
  point(dd nx , dd ny) { x  = nx ; y = ny; };
  point(){};
};
point origin; // origin point to convex hull

bool operator <(point A , point B);
point operator +(point A , point B);
point operator -(point A , point B);
dd operator *(point A, point B);
dd operator ^(point A, point B);
dd area(vector<point> & P );
dd norma(point A);
dd angle(point A, point B);
dd lineTopoint(point A ,point B , point C);
bool cmpcross(point A , point B);
bool cmpatan(point A , point B);
point getOrigin(vector<point> & P);
vector<point> ConvexHull(vector<point> & P);

// All points represent vectors

int main()
{
  int n; cin >> n;
  vector<point> p(n);
  for(int i = 0 ; i < n ; ++i)
    {
      int x , y; cin >> x >> y;
      p[i] = point(x,y);
    }
  vector<point> convex = ConvexHull(p);
  for(int i = 0 ; i < convex.size() ; ++i)
    cout << convex[i].x << " "<< convex[i].y << "\n";
  return 0;
}

bool operator<(point A, point B)
{
  return norma(A)  < norma(B);
}
point operator +(point A , point B)
{
  return point(A.x+B.x,A.y+B.y);
}

point operator -(point A ,point B)
{
 return point(A.x - B.x , A.y - B.y);
}

dd operator *(point A , point B) // dot product
{
  return A.x * B.x + A.y * B.y;
}

dd operator ^(point A , point B) // cross product
{
  return A.x * B.y - A.y * B.x;
}

dd area(vector< point > & P) // area between two vectors
{
  sort(P.begin() , P.end() , cmpatan);
  P.push_back(P[0]);
  dd acum=0;
  for(int i = 0 ; i < P.size()-1 ; ++i) // n es el numero de puntos(posiblemente mas el primer punto
    {                          // para evitar ifs
      acum += (P[i] ^ P[i+1]) ;
    }
  return abs(acum/2);
}
dd norma(point A)
{
  return sqrt( (A.x)*(A.x) + (A.y)*(A.y) );
}

dd angle( point A , point B)
{
  // cout <<  norma(A)*norma(B)  << "\n"; 
  return acos( (A*B) / (norma(A)*norma(B)) ) ;
}

dd lineTopoint(point A , point B, point C, bool segment) // AB defines the line and C is the point
{
  point AB = B-A; point AC = C-A; point BC = C-B;
  dd dist = (AB^AC)/norma(AB);
  if(segment)
    {
      if(AB * BC > 0)
	return norma(BC);
      if( (A-B) * (A-C) > 0)
	return norma(A-C);
    }
  return abs(dist);
}

bool cmpatan(point A, point B)
{
  if( atan2(A.y,A.x) == atan2(B.y, B.x) )
    {
      return A < B;
    }
  return (atan2(A.y,A.x) < atan2(B.y, B.x));
}
bool cmpcross(point x, point y)
{
  point ox = x - origin;
  point oy = y - origin;
  if( (ox ^ oy) == (oy ^ ox))
    {
      return (origin - x) <  (origin - y);
    }
  return (ox ^ oy)  > (oy ^ ox);
}

point getOrigin(vector<point> & P) // The most down point and leftmost.
{
  point orig = P[0];
  for(int i = 1 ; i < P.size() ; ++i)
    {
      if(P[i].y < orig.y)
	{
	  orig = P[i];
	}
      if(P[i].y == orig.y)
	{
	  if(P[i].x < orig.x)
	    orig = P[i];
	}
    }
  return orig;
}

vector< point > ConvexHull( vector<point> & P)
{
  vector<point> ans;
  if(P.size() < 3 ) return P;
  origin =  getOrigin(P);
  // cout << "origen: "<<origin.x << origin.y << "\n";
  sort(P.begin(), P.end(),cmpcross);
  // for(int i = 0 ; i < P.size() ; ++i)
  //   cout << i << ": "<< P[i].x << " " << P[i].y << "\n";
  stack< point > pila;
  pila.push(P[0]);  pila.push(P[1]);
  for(int i = 2 ; i < P.size();)
    {
      point a = pila.top(),b;
      pila.pop();
      if(pila.size() >= 1)
	b = pila.top();
      pila.push(a);
      // cout << " a: "<< a.x << " " << a.y   << "b: " << b.x <<"   " <<  b.y  << "\n";
      if(pila.size() > 1 && ((P[i]-a)^(b-a)) <= 0)
	pila.pop();
      else
	{
	  pila.push(P[i]);
	  ++i;
	}      
    }
  while(!pila.empty())
    ans.push_back(pila.top()), pila.pop();
  return ans;
}
