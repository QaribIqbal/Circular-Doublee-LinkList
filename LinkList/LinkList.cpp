#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node* prev;
	node() :data(-1), next(nullptr), prev(nullptr) {};
	node(int val) :data(val), next(nullptr), prev(nullptr) {};
};
class CDLL {
private:
	node* head;
	node* tail;
public:
	CDLL() :head(nullptr), tail(nullptr) {};
	void insertAtEnd(int val)
	{
		if (head == nullptr)
		{
			head = new node(val);
			tail = head;
			head->next = tail;
			tail->prev = head;
		
		}
		else {
			tail->next = new node(val);
			tail->next->prev = tail;
			tail = tail->next;
			tail->next = head;
			head->prev = tail;
		
		}
	}
	void insertAtBegin(int val) {
		if (head == nullptr)
		{
			head = new node(val);
			head->next = head;
			tail = head;
			tail->prev = head;
		}
		else {
			head->prev = new node(val);
			head->prev->prev = tail;
			head->prev->next = head;
			head = head->prev;
			tail->next = head;
		}
	}
	void display()
	{
		node* curr = head;
		do {
			cout << curr->data << "  ";
			curr = curr->next;
		} while (curr != head);
	}
	void displayReverse()
	{
		node* curr = tail;
		{
			do {
				cout << curr->data << " ";
				curr = curr->prev;
			} while (curr != tail);
		}
	}
	void deleteVal(int val)
	{
		if (head == nullptr)
		{
			cout << "\nList is empty\n";
			return;
		}
		else {
			if (head->next == head)
			{
				head = nullptr;
				return;
			}
		node* curr = head;
		do {
			if (curr->data == val)
			{
				if (curr == head)
				{
					head = head->next;
					tail->next = head;
					head->prev = tail;
					return;
				}
				else if (curr == tail)
				{
					tail = tail->prev;
					head->prev = tail;
					tail->next = head;
					return;
				}
				node* temp = curr->prev;
				temp->next = curr->next;
				curr->next->prev = temp;
				return;
			}
			curr = curr->next;
		} while (curr != head);
		}
	}
};
int main()
{
	CDLL list;
	list.insertAtEnd(3);
	list.insertAtEnd(4);
	list.insertAtBegin(2);
	list.insertAtBegin(1);
	list.display();
	cout << endl;
	list.displayReverse();
	list.deleteVal(4);
	cout << endl;
	list.display();
	return 0;
}