#include <bits/stdc++.h>
using namespace std;
// For more info, you can visit:
// http://book.huihoo.com/pdf/cs-373-combinatorial-algorithms/
// CLRS(For amortized Analysis)
typedef int treetp;

struct Node {
  Node * childs[2];
  Node * parent;
  treetp data;
  Node(Node * nparent, Node * left , Node * right, treetp ndata) 
  {  parent  = nparent, childs[0] = left , childs[1] = right , data = ndata; }  ;
};

Node * root;

void rotate(Node * & x) // x = node to splay
{
  // y = parent(x) , z = parent(parent(x)) = grandpa(x)
  Node * y = x->parent;   
  Node * z = y->parent;
  bool yside = !(y->childs[0] == x);
  
  if(x->childs[!yside])
    {
      y->childs[yside] = x->childs[!yside];
      x->childs[!yside]->parent = y;
    }
  else
    y->childs[yside] = NULL;

  x->childs[!yside] = y;
  
  if(z)
    {
      bool zside = !(z->childs[0] == y);
      z->childs[zside] = x;
      x->parent = z;
    }
  else x->parent = NULL;
  y->parent = x;
}

void Splay(Node * & x)
{
  while(x->parent)
  {
    Node * y = x->parent;
    Node * z = y->parent;
    bool yside = !(y->childs[0] == x);
    if(!z) // simple rotation
      {
	rotate(x);
	break;
      }
    bool zside = !(z->childs[0] == y);
    // double rotations
    if(yside == zside) //zig zig
      rotate(y) , rotate(x);
    else // zig zag
      rotate(x) , rotate(x);
  }
  root = x; // maybe unneccesary
}

Node * Find(treetp key, Node * & r)
{
  bool side;
  if(r==0 && r == root)  return 0;
  if(r->data==key && r == root) return r;

  while(true)
    {
      side = (r->data < key);
      if(r->data == key)  break;
      if(r->childs[side]) r = r->childs[side];
      else break;	
    }
  
  Splay(r);
  if(r->data == key) return r;
  else return NULL;
}

bool Insert(treetp key)
{
  if(!root)
    {
      root = new Node(NULL,NULL,NULL,key) ;
      return 1;
    }
  Node * r = root;
  bool insert=0;
  while(!insert)
    {
      if(r->data == key){
	Splay(r); // importante xD
	return 0;
      }
      bool side = (r->data < key);
      if(r->childs[side]) r = r->childs[side];
      else
	r->childs[side] = new Node(r,NULL,NULL,key) , r = r->childs[side] , insert = 1;      
    }
  Splay(r);
  return 0;
}

bool Erase(treetp key) 
{
  Node * r  = Find(key,root); 
  if(!r) return 0;
  Node * left = r->childs[0];
  if(!left)
    {
      root = r->childs[1];
      if(root) root->parent = NULL;
      free(r);
      return 1;
    }
  while(left->childs[1]) left = left->childs[1]; // we go all right

  root = r->childs[0];
  root->parent = NULL;
  Splay(left);
  if(r->childs[1])
    {
      root->childs[1] =r->childs[1];
      r->childs[1]->parent = root;
    }
  free(r);  
  return 1;
}

void Inorder(Node * r)
{
  if(r)
    {
      Inorder(r->childs[0]);
      printf("%d ",r->data); // problems with typedef
      Inorder(r->childs[1]);
    }
  // printf("\n");
}


int main()
{
  ios_base::sync_with_stdio(0);
  char k;
  int n,c,rpta; scanf("%d",&n);
  while(n--)
    {
      scanf(" %c %d",&k,&c);
      if(k == 'I')
	Insert(c);
      if(k == 'D')
	Erase(c);
    }

  return 0;
}
