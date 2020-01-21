#include<iostream>
#include<string>

using namespace std;

struct LinkedList
{
	int value;
	LinkedList *next;
};

LinkedList* append_node(int, LinkedList*);
LinkedList* insert_node(int, int, LinkedList*);
LinkedList* delete_node(int, LinkedList*);
int search_node(int, LinkedList*);
void destroy_list(LinkedList*);

int main()
{
	LinkedList* head = new LinkedList;
	LinkedList* new_node = nullptr;
	LinkedList* ptr = nullptr;

	int choice;

	//asking user for the number of nodes they want on the list
	do
	{
		cout << "Enter the number of initial nodes (must be at least 1): ";
		cin >> choice;
	} while (choice < 1);

	cout << endl;

	int num;

	//build the linked list
	for (int i = 0; i < choice; i++)
	{
		cout << "Enter a number: ";
		cin >> num;
		if (i == 0)
		{
			head->value = num;
			head->next = nullptr;
		}
		else
		{
			ptr = append_node(num, head);
		}
	}

	//print out the content of the linked list
	cout << "\nHere are the initial values in the linked list: " << endl;

	while (ptr != nullptr)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}

	//test the insert_function
	int pos;
	cout << "\nEnter the number that you want to insert: ";
	cin >> num;
	cout << "Enter the position that you want to insert: ";
	cin >> pos;
	ptr = insert_node(num, pos, head);
	head = ptr;

	cout << "\nHere is the updated linked list: " << endl;
	while (ptr != nullptr)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}

	//test the delete_node function
	cout << "\nEnter the position that you want to delete: ";
	cin >> pos;
	ptr = delete_node(pos, head);
	head = ptr;

	cout << "\nHere is the updated linked list: " << endl;
	while (ptr != nullptr)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}

	//test serch_node function
	cout << "\nEnter the number that you want to search for in the list: ";
	cin >> num;

	int index = search_node(num, head);
	cout << "Number found at the index " << index << " in the linked list" << endl << endl;

	//test destroy_list function
	destroy_list(head);

	system("PAUSE");
	return 0;
}

LinkedList* append_node(int num, LinkedList* head)
{
	LinkedList* ptr = head;
	LinkedList* new_node = new LinkedList;

	new_node->value = num;
	new_node->next = nullptr;

	while (ptr->next != nullptr)
	{
		ptr = ptr->next;
	}

	ptr->next = new_node;

	return head;
}

// TODO: Fill in
LinkedList* insert_node(int num, int pos, LinkedList* head)
{
	// Insert Node with value NUM into position POS of the list HEAD

	// Initialize ptr and new_node
	LinkedList* ptr = head;
	LinkedList* new_node = new LinkedList;
	new_node->value = num;
	new_node->next = nullptr;

	if (pos == 0)
	{
		// Then new_node is the new head
		new_node->next = head;
		return new_node;
	}

	// Go to the position POS
	for (int i = 0; i < pos - 1; i++)
	{
		ptr = ptr->next;
	}
	// Insert new_node to the list
	new_node->next = ptr->next;
	ptr->next = new_node;

	return head;
}

// TODO: Fill in
LinkedList* delete_node(int pos, LinkedList* head)
{
	// Delete node at the position POS from the list HEAD

	// Initialize ptr
	LinkedList* ptr = head;

	if (pos == 0)
	{
		// Then head->next is the new head
		LinkedList* new_head = head->next;
		delete head;
		head = nullptr;
		return new_head;
	}


	// Go to the position POS
	for (int i = 0; i < pos - 1; i++)
	{
		ptr = ptr->next;
	}

	// Delete node at the position
	LinkedList* ptr2 = ptr->next;
	ptr->next = ptr2->next;

	delete ptr2;
	ptr2 = nullptr;

	return head;
}

// TODO: Fill in
int search_node(int num, LinkedList* head)
{
	// Return the index of the node with value NUM in the list HEAD.
	// Return -1 if NUM is not in the list
	int idx = -1;
	int index = 0;
	LinkedList* ptr = head;

	while (ptr->next != nullptr && ptr->value != num)
	{
		ptr = ptr->next;
		index++;
	}

	if (ptr->value == num)
		idx = index;

	return idx;
}

// TODO: Fill in
void destroy_list(LinkedList* head)
{
	LinkedList* ptr = head;

	// Destroy the list HEAD to free memory
	while (ptr->next != nullptr)
	{
		LinkedList* ptr2 = nullptr;
		ptr2 = ptr;
		ptr = ptr->next;
		delete ptr2;
		ptr2 = nullptr;
	}

	delete head;
	ptr = head = nullptr;

}