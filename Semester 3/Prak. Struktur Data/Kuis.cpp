#include <stdio.h>
#include <stdlib.h>
typedef struct typenode *typeptr;
typedef struct typenode
{
  int info;
  typeptr next;
} typenode;
int main()
{
  typeptr a, b, c, d;
  a = (typenode *)malloc(sizeof(typenode));
  b = (typenode *)malloc(sizeof(typenode));
  d = b;
  a->info = 20;
  b->info = 4 * a->info - 10; // 70
  c = a;
  d->next = a;
  c->next = d;
  c->info = 2 * d->info; // 140
  b->next = c; // b->c->d->a
  b->info = 30;
  printf("a->next->info = %d\n", a->next->info); // 30
  printf("b->next->info = %d\n", b->next->info); // 140
  printf("c->next->info = %d\n", c->next->info); // 30
  printf("d->next->info = %d ", d->next->info); // 140
  return 0;
}