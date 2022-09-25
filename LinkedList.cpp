#include <iostream>

using namespace std;

template < typename L > class List
{
public:
  List ();
  ~List ();

  void push_back (L data);
  void pop_front ();
  void reverseList ();
  void clear ();
  int getSize ()
  {
    return Size;
  }
  L & operator[](const int index);

private:
  template < typename T > class Node
  {
  public:
    Node * pNext;
    T data;
    Node (T data = T (), Node * pNext = nullptr)
    {
      this->data = data;
      this->pNext = pNext;
    }
  };
  int Size;
  Node < L > *head;
};

template < typename L > List < L >::List ()
{
  Size = 0;
  head = nullptr;
}

template < typename L > List < L >::~List ()
{
  clear ();
}

template < typename L > void List < L >::push_back (L data)
{
  if (head == nullptr)
    {
      head = new Node < L > (data);
    }
  else
    {
      Node < L > *current = this->head;
      while (current->pNext != nullptr)
	{
	  current = current->pNext;
	}
      current->pNext = new Node < L > (data);
    }
  Size++;
}

template < typename L > L & List < L >::operator[](const int index)
{
  int counter = 0;
  Node < L > *current = this->head;
  while (current != nullptr)
    {
      if (counter == index)
	{
	  return current->data;
	}
      current = current->pNext;
      counter++;
    }
}

template < typename L > void List < L >::pop_front ()
{
  Node < L > *temp = head;
  head = head->pNext;
  delete temp;
  Size--;
}

template < typename L > void List < L >::clear ()
{
  while (Size)
    {
      pop_front ();
    }
}

template < typename L > void List < L >::reverseList ()
{
  Node < L > *current = head;
  Node < L > *prev = nullptr;
  Node < L > *next = nullptr;
  while (current != NULL)
    {
      next = current->pNext;
      current->pNext = prev;
      prev = current;
      current = next;
    }
  head = prev;
}

int
main ()
{
  cout << "Hello World" << endl;
  List < int >first;
  first.push_back (5);
  first.push_back (7);
  first.push_back (11);
  first.push_back (15);
  first.push_back (18);
  first.push_back (19);
  first.push_back (34);
  // cout << first.getSize()<< endl;
  // cout << first[1] << endl;
  // first.reverse();

  first.pop_front ();
  for (int i = 0; i < first.getSize (); i++)
    {
      cout << first[i] << endl;
    }
  cout << "--------------------------------" << endl;

  first.reverseList ();
  for (int i = 0; i < first.getSize (); i++)
    {
      cout << first[i] << endl;
    }

  return 0;
}
