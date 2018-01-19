#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define geth(n) (n->h = 1 + max(n->l->h, n->r->h))

struct node
{
      int key, h;
      struct node *l, *r;
} *R, *NIL;
typedef struct node node;

void init(void)
{
      R = NIL = (node *) malloc(sizeof(node));
      NIL->key = NIL->h = 0,
              NIL->l = NIL->r = NULL;
}

node* rotleft(node *n)
{
      node *t = n->l;

      n->l = t->r, t->r = n,
              geth(n), geth(t);
      return t;
}

node* rotright(node *n)
{
      node *t = n->r;

      n->r = t->l, t->l = n,
              geth(n), geth(t);
      return t;
}

node* balance(node *n)
{
      geth(n);
      if (n->l->h > n->r->h + 1)
      {
              if (n->l->r->h > n->l->l->h)
                      n->l = rotright(n->l);
              n = rotleft(n);
      }
      else
              if (n->r->h > n->l->h + 1)
              {
                      if (n->r->l->h > n->r->r->h)
                              n->r = rotleft(n->r);
                      n = rotright(n);
              }
      return n;
}

node* insert(node *n, int key)
{
      if (n == NIL)
      {
              n = (node *) malloc(sizeof(node));
              n->key = key, n->h = 1, n->l = n->r = NIL;
              return n;
      }
      if (key < n->key)
              n->l = insert(n->l, key);
      else
              n->r = insert(n->r, key);
      return balance(n);
}

node* erase(node *n, int key)
{
      node *t;
      if (n == NIL) return n;
      if (n->key == key)
      {
              if (n->l == NIL || n->r == NIL)
              {
                      t = n->l == NIL ? n->r : n->l;
                      free(n); return t;
              }
              else
              {
                      for (t = n->r; t->l != NIL; t = t->l);
                      n->key = t->key,
                              n->r = erase(n->r, t->key);
                      return balance(n);
              }
      }
      if (key < n->key)
              n->l = erase(n->l, key);
      else
              n->r = erase(n->r, key);
      return balance(n);
}

int search(node *n, int key)
{
      if (n == NIL) return 0;
      if (n->key == key) return 1;
      if (key < n->key)
              return search(n->l, key);
      else
              return search(n->r, key);
}

int maxim(node *n)
{
    //nu mai exista nod in dreapta
    if(n->r == NIL)
    {
        return n->key;
    }

    return maxim(n->r);
}

void afis(node *n)
{
    if(n == NIL)
        return;

    afis(n->l);
    printf("%d ",n->key);
    afis(n->r);
}

int main()
{
    int i;

    init();

    R = insert(R, -10);
    for(i=10;i;i--)
        R = insert(R, i);
    R = insert(R, 100);

    ///-10, 10 -> 1, 100
    afis(R);
    printf("\n");

    R = erase(R, 10);

    ///-10, 9 -> 1, 100
    afis(R);
    printf("\n");


    ///afisaza daca exista el in avl
    int el = 100;
    if(search(R, el))
        printf("%d exista in avl\n",el);
    else
        printf("%d nu exista in avl\n",el);

    return 0;
}
