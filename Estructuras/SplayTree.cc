#include <bits/stdc++.h>
using namespace std;

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
    if(!z) // simple rotation
      rotate(x);
    else // double rotation
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
      if(r->data == key) return 0;
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
  while(true)
    {
      int opt;
      scanf("%d",&opt);
      if(opt == 0) // Insert
	{
	  treetp v; scanf("%d",&v);
	  Insert(v);
	}
      if(opt == 1) // Find
	{
	  treetp v; scanf("%d",&v);
	  Find(v,root);
	}
      if(opt == 2)
	{
	  treetp v; scanf("%d",&v);
	  Erase(v);
	}
      if(opt == 3) break;	
      if(root)Inorder(root), printf("root: %d \n",root->data);
    }
  return 0;
}
