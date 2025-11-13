#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d) // Insert elements in Queue
{
  struct node *n;
  n = new struct node;
  n->data = d;
  n->next = NULL;
  if ((r == NULL) && (f == NULL))
  {
    f = r = n;
    r->next = f;
  }
  else
  {
    r->next = n;
    r = n;
    n->next = f;
  }
}

void dequeue() // Delete an element from Queue
{
  struct node *t;
  t = f;
  if ((f == NULL) && (r == NULL))
    cout << "\nQueue is Empty";
  else if (f == r)
  {
    f = r = NULL;
    delete t;
  }
  else
  {
    f = f->next;
    r->next = f;
    delete t;
  }
}

void display()
{ // Print the elements of Queue
  struct node *t;
  t = f;
  if ((f == NULL) && (r == NULL))
    cout << "\nQueue is Empty";
  else
  {
    do
    {
      cout << " " << t->data;
      t = t->next;
    } while (t != f);
  }
}

int main()
{
  enqueue(34);
  enqueue(22);
  enqueue(75);
  enqueue(99);
  enqueue(27);
  cout << "Circular Queue: ";
  display();
  cout << endl;

  dequeue();
  cout << "Circular Queue After dequeue: ";
  display();
  return 0;
}

