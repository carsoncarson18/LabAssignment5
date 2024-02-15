#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char letter;
	struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length(node *head)
{
	node *current = head;
	int count = 0;

	// traverse linked list & count number of nodes
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char *toCString(node *head)
{

	int len = length(head);
	char *letters = malloc(len + 1);
	node *current = head;

	// traverse list & store each nodes letter in the new string
	for (int i = 0; i < len; i++)
	{
		letters[i] = current->letter;
		current = current->next;
	}

	// denote end of string
	letters[len] = '\0';

	return letters;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c)
{
	// declare & initialize new node
	node *newNode = (node *)malloc(sizeof(node));
	newNode->letter = c;
	newNode->next = NULL;

	// check if list is empty
	if (*pHead == NULL)
	{
		*pHead = newNode;
	}
	else
	// traverse and add new char to the end of the list
	{
		node *current = *pHead;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node **pHead)
{
	node *current = *pHead;

	// traverse & delete each node in list
	while (current != NULL)
	{
		*pHead = current->next;
		free(current);
		current = *pHead;
	}
}

int main(void)
{
	int i, strLen, numInputs;
	node *head = NULL;
	char *str;
	char c;
	FILE *inFile = fopen("input.txt", "r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile, " %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}