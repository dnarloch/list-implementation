#include <stdio.h>

struct Node
{
	struct Node * prev;
	struct Node * next;
	int value;
	Node(int x) : prev(NULL), next(NULL), value(x) {};
	Node(): prev(NULL), next(NULL), value(NULL){};
};
	
class List
{
private:
	Node *head;
	Node *tail;
	int length;
	void increaseLength() { this->length++; };
	void decreaseLength() { this->length--; };
	
public: 
	List() :length(0), head(NULL), tail(NULL) {};

	Node* getHead() { return this->head; };
	Node* getTail() { return this->tail; };
	int getLength() { return this->length; };
	void setHead(Node* h) { this->head = h; };
	void setTail(Node* t) { this->tail = t; };
	
	void AddFront(int v)
	{
		Node* newNode = new Node(v);
		if (this->length == 0)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else 
		{
			newNode->next = this->head;
			(this->head)->prev = newNode;
			this->head = newNode;
		}
		increaseLength();
	};
	void AddBack(int v)
	{
		Node* newNode = new Node(v);
		if (this->length == 0)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else 
		{
			newNode->prev = this->tail;
			(this->tail)->next = newNode;
			this->tail = newNode;
		}
		increaseLength();
	};
	void Insert(int v)
	{
		Node* newNode = new Node(v);
		if (this->head == NULL) 
		{
			this->head = newNode;
			increaseLength();
		}
		else if ((this->head)->value >= v)
		{
			newNode->next = this->head;
			(this->head)->prev = newNode;
			this->head = newNode;
			increaseLength();
		}
		else
		{
			Node* tmp = this->head;
			while (tmp->value < v)
			{
				if (tmp->next != NULL)
					tmp = tmp->next;
				else
				{
					newNode->prev = this->tail;
					(this->tail)->next = newNode;
					this->tail = newNode;
					increaseLength();
				}
			}
			tmp->prev->next = newNode;
			newNode->prev = tmp->prev;
			newNode->next = tmp;
			tmp->prev = newNode;
			increaseLength();
		}
	};
	void DeleteFront()
	{
		Node* tmp = this->head;
		this->head = tmp->next;
		tmp->prev = NULL;
		decreaseLength();
	};
	void DeleteBack()
	{
		Node* tmp = this->tail;
		this->tail = (this->tail)->prev;
		(this->tail)->next = NULL;
		decreaseLength();
	};
	void swapNodes(Node* a, Node* b)
	{
		int tmp = a->value;
		a->value = b->value;
		b->value = tmp;
	};
	void BubbleSortList()
	{
		int size = this->length;
		Node* tmp = this->head;
		for (int j = 0; j < size-1; j++)
		{
			for (int i = 0; i < size - j -1; i++)
			{
				if (tmp->value > tmp->next->value)
					swapNodes(tmp, tmp->next);
				tmp = tmp->next;
			}
			tmp = this->head;
		}
	};
	void printList() 
	{
		int i = 0;
		Node* tmp = this->head;
		while (tmp != NULL) 
		{
			printf("%d. %d\n", ++i, tmp->value);
			tmp = tmp->next;
		}
	};
};

int main()
{
	List intList;
	intList.AddBack(5);
	intList.AddBack(50);
	intList.AddBack(0);
	intList.AddBack(1);
	intList.AddBack(-2);
	intList.AddFront(9);
	intList.AddFront(74);
	intList.AddFront(15);
	intList.AddFront(6);
	intList.printList();
	printf("\n");
	intList.DeleteBack();
	intList.DeleteFront(); 
	intList.printList();
	printf("\n");
	intList.BubbleSortList();
	intList.printList();
	printf("\n");
	intList.Insert(34);
	intList.printList();
}