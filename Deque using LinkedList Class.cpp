#include <iostream>
using namespace std;
class Node
{
	int data;
	Node* next;
public:
	void setData(int data)
	{
		this->data = data;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	int getData()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}
	Node(int data = 0, Node* next = NULL)
	{
		setData(data);
		setNext(next);
	}

};
class LinkedList
{
	Node* head;
public:
	void setHead(Node* head)
	{
		this->head = head;
	}
	Node* getHead()
	{
		return head;
	}
	LinkedList(Node* head = NULL)
	{
		setHead(head);
	}
	bool isEmpty()
	{
		return (head == NULL) ? true : false;
	}
	void insertAtBeginning(int data)
	{
		if (isEmpty())
		{
			Node* t = new Node(data);
			head = t;
		}
		else
		{
			Node* t = new Node(data);
			t->setNext(head);
			head = t;
		}
	}
	void insertAtLast(int data)
	{
		if (isEmpty())
		{
			Node* t = new Node(data);
			head = t;
		}
		else
		{
			Node* t = new Node(data);
			Node* last = head;
			while (last->getNext() != NULL)
			{
				last = last->getNext();
			}
			last->setNext(t);
		}
	}
	bool removeFromBeginning()
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			Node* t = head->getNext();
			delete head;
			head = t;
			return true;
		}
	}
	int getLenght()
	{
		int lenght = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			lenght++;
			temp = temp->getNext();
		}
		return lenght;
	}
	bool removeFromLast()
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			int lenght = getLenght();
			if (lenght == 1)
			{
				delete head;
				head = NULL;
				return true;
			}

			Node* temp = head;
			while (temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}
			delete temp;
			temp = head;
			for (int i = 0; i < lenght - 2; i++)
			{
				temp = temp->getNext();
			}
			temp->setNext(NULL);
			return true;
		}
	}
	int getFirstElement()
	{
		return head->getData();
	}
	int getLastElement()
	{
		if (isEmpty())
			return NULL;

		Node* last = head;
		while (last->getNext() != NULL)
		{
			last = last->getNext();
		}
		return last->getData();
	}
	void print()
	{
		cout << endl;
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->getData() << endl;
			temp = temp->getNext();
		}
	}
	int getNthElement(int n)//To get nth term
	{
		int lenght = getLenght();
		if (n <= lenght)
		{
			if (n == 1)
			{
				return head->getData();
			}
			else
			{
				Node* temp = head;
				for (int i = 0; i < n - 1; i++)
				{
					temp = temp->getNext();
				}
				return temp->getData();
			}
		}
		else
		{
			cout << n << " term is out of range of size of this Linked List.";
			return NULL;
		}

	}
};
class Deque
{
	LinkedList l1;
public:
	void push_Front(int val)
	{
		l1.insertAtBeginning(val);
	}
	void push_Back(int val)
	{
		l1.insertAtLast(val);
	}
	int pop_Back()
	{
		if (l1.isEmpty())
		{
			cout << "\nCan't pop because Deque is Empty(0).";
			return NULL;
		}
		int data = l1.getLastElement();
		l1.removeFromLast();
		return data;
	}
	int pop_Front()
	{
		if (l1.isEmpty())
		{
			cout << "\nCan't pop because Deque is Empty(0).";
			return NULL;
		}
		int data = l1.getFirstElement();
		l1.removeFromBeginning();
		return data;
	}
	int getFront()
	{
		if (l1.isEmpty())
		{
			cout << "\nNo Front-end value because Deque is Empty(0).";
			return NULL;
		}
		return l1.getFirstElement();
	}
	int getBack()
	{
		if (l1.isEmpty())
		{
			cout << "\nNo Back-end value because Deque is Empty(0).";
			return NULL;
		}
		return l1.getLastElement();
	}
	int getSize()
	{
		return l1.getLenght();
	}
	bool isEmpty()
	{
		return (l1.isEmpty()) ? true : false;
	}
	void printDeque()
	{
		cout << endl << "\nDeque elements are\n";
			l1.print();
	}
};
int main()
{
	Deque d1;
	for (int i = 0; i < 20; i++)
	{
		d1.push_Front(i + 1);
		d1.push_Back(i+1);
	}
	d1.printDeque();

	cout << endl << "Size of Deque is " << d1.getSize();

	cout<<endl<<"Last element of Deque is "<<d1.getBack();
	cout << endl << "First element of Deque is " << d1.getFront();

	double product = 1;
	for (int i = 1; i <= 20; i++)
		product = product * d1.pop_Front();

	cout << "\nProduct of first 20 number is " << product;

	cout << "\nAfter poping from front 20 elements deque is \n";
	d1.printDeque();

	product = 1;
	for (int i = 0;i < 20; i++)
		product = product * d1.pop_Back();

	if(d1.isEmpty())
		cout << "\nProduct of remaining 20 number is " << product;

	d1.pop_Back();
	d1.pop_Front();
	
    return 0;
}
