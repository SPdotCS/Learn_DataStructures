// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct Node
{
	int data;
	Node* prev;
	Node* next;
};
Node* GetNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

Node* InsertAtHead(int data, Node *node)
{
	Node* curNode = GetNode(data);
	if (node == NULL)
		return curNode;
	node->prev = curNode;
	curNode->next = node;
	return curNode;
}

Node* InsertAtTail(int data, Node *node)
{
	Node* curNode = GetNode(data);
	if (node == NULL)
		return curNode;
	curNode->prev = node;
	node->next = curNode;
	return curNode;
}

void print(Node* node)
{
	std::cout << "Here is the list \n";

	do
	{
		std::cout << node->data;
		std::cout << "\n";
		if (node->next == NULL)
			break;
		node = node->next;
	} while (node != NULL);


	std::cout << "Here is the reverse list \n";

	do
	{
		std::cout << node->data;
		std::cout << "\n";
		if (node->prev == NULL)
			break;
		node = node->prev;
	} while (node != NULL);
}

int main()
{
	Node* headNode = NULL;
	headNode = InsertAtHead(2, headNode);
	headNode = InsertAtHead(3, headNode);
	headNode = InsertAtHead(4, headNode);
	print(headNode);

	Node* tailNode = NULL;
	Node* newHead = NULL;
	newHead = InsertAtTail(2, newHead);
	tailNode = InsertAtTail(4, newHead);
	tailNode = InsertAtTail(6, tailNode);

	print(newHead);
	//std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
