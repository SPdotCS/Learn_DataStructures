// ReverseLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#pragma region LinkedListFunctions
struct Node
{
	int data;
	Node* link;
};
Node* GetLastNode(Node * headNode)
{
	Node* temp = headNode;
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	return temp;
}

Node* GetNode(int position, Node* headNode)
{
	if (position == 1)
	{
		return headNode;
	}
	else
	{
		Node* nthNode = NULL;
		for (int i = 0; i < position; i++)
		{
			nthNode->link = headNode->link;
		}
		return nthNode;
	}
}
Node* Insert(int data, Node* head)
{
	if (head == NULL)
	{
		head = new Node();
		head->data = data;
		head->link = NULL;
	}
	else
	{
		Node* temp = GetLastNode(head);
		Node* tempNode = new Node();
		tempNode->data = data;
		tempNode->link = NULL;
		temp->link = tempNode;
	}
	return head;
}
Node* Insert(int data, Node* headNode, int position, bool IsReplace)
{
	if (position == 1)
	{
		if (IsReplace)
		{
			headNode->data = data;
			return headNode;
		}
		Node* newNode = new Node();
		newNode->data = data;
		newNode->link = headNode;
		return newNode;
	}
	else
	{
		Node* tempNode = IsReplace ? headNode->link : headNode;
		for (int i = 1; i < position - 1; i++)
		{
			if (tempNode == NULL)
				return tempNode;
			tempNode = tempNode->link;
		}
		if (!IsReplace)
		{
			Node* newNode = new Node();
			newNode->data = data;
			newNode->link = tempNode->link;
			tempNode->link = newNode;
			return headNode;
		}
		tempNode->data = data;
		return headNode;
	}
}


Node* Delete(int position, Node* headNode)
{
	Node* tempNode1 = headNode;
	if (position == 1)
	{
		tempNode1 = headNode->link;
		delete headNode;
		return tempNode1;
	}
	else
	{

		for (int i = 1; i < position - 1; i++)
		{
			if (tempNode1 == NULL)
				return tempNode1;
			tempNode1 = tempNode1->link;
		}
		Node* tempNode = tempNode1->link;
		tempNode1->link = tempNode->link;
		delete tempNode;
		return headNode;
	}
}
void PrintList(Node* headNode)
{
	std::cout << "Here is the node values are \n";
	Node* temp = headNode;
	while (temp != NULL)
	{
		std::cout << temp->data;
		temp = temp->link;
		std::cout << "\n";
	}
}

Node* createInitialList(Node* headNode)
{
	std::cout << "Enter the length of linked list: \n";
	int length;
	std::cin >> length;

	for (int i = 0; i < length; i++)
	{
		std::cout << "Enter the value of the node: \n";
		int data;
		std::cin >> data;
		headNode = Insert(data, headNode);
	}
	return headNode;
}

void playwithList(Node* headNode)
{
	char choice = 'N';
	do {
		std::cout << "\nSelect the operation you want to perform";
		std::cout << "\n1.Add";
		std::cout << "\n2.Edit";
		std::cout << "\n3.Delete\n";

		int option = 0;
		std::cin >> option;

		if (option > 0 && option < 4)
		{
			int position;
			int nodeValue;
			std::cout << "\nEnter the position of the node:";
			std::cin >> position;
			if (option == 1)
			{
				std::cout << "\nEnter the value of the node:";
				std::cin >> nodeValue;
				headNode = Insert(nodeValue, headNode, position, false);
				PrintList(headNode);
			}
			else if (option == 2)
			{
				std::cout << "\nEnter the value of the node:";
				std::cin >> nodeValue;
				headNode = Insert(nodeValue, headNode, position, true);
				PrintList(headNode);
			}
			else
			{
				headNode = Delete(position, headNode);
				PrintList(headNode);
			}
		}
		else
		{
			std::cout << "\nInvalid selection";
		}
		std::cout << "\nDo you want to continue(Y/N)?";
		std::cin >> choice;
	} while (choice == 'Y');
}

Node* ReverseIterative(Node* headNode)
{
	Node* currentNode = headNode;
	Node* prev = NULL;
	Node* next = NULL;

	while (currentNode != NULL)
	{
		next = currentNode->link;
		currentNode->link = prev;
		if (next == NULL)
			return currentNode;
		prev = currentNode;
		currentNode = next;
	}
	return currentNode;
}

Node* RecursiveReverse(Node* node)
{
	if (node->link == NULL)
		return node;
	Node* prevNode = RecursiveReverse(node->link);
	prevNode->link = node;
	return node;
}
#pragma endregion

int main()
{
	Node* headNode = NULL;
	headNode = createInitialList(headNode);
	PrintList(headNode);
	//playwithList(headNode);
	std::cout << "Reversing the list\n";
	headNode = ReverseIterative(headNode);
	PrintList(headNode);

	std::cout << "Reversing the list\n";

	headNode = RecursiveReverse(headNode);
	PrintList(headNode);
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
