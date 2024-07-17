#include <iostream>

using namespace std;

struct node
{
	int item; 
	node* next;
	node(int z, node* t = 0)
	{
		item = z; 
		next = t;
	};
};
typedef node* link;

void printList(link n) {
	while (n != NULL)
	{
		cout << n->item << " ";
		n = n->next;
	}
}

void display(link head);

int main()
{
	int z, n;
	cin >> z;
	link head = NULL;

	if (z >= 1 && z <= 20) {
		for (int i = 0; i < z; i++)
		{
			cin >> n;
			int tmp = n;
			if (n >= 1 && n <= 100) {
				while (n != 0)
				{
					int liczba;
					cin >> liczba;
					link next = head;

					head = new node(liczba, next);
					if (head->next != NULL)
						head->next = next;

					n--;
				}
			}
			else
				i--;

			cout << endl;
			//printList(head);
			display(head);
			delete (head);
		}
	}


	return 0;
}

void display(link head) {
	link temp;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->item << "\t";
		temp = temp->next;
	}
}