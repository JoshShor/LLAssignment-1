/*
* Name: Joshua Shor
* Student ID: 200968955
* Email: shor002@cougars.csusm.edu
*
Assume we use two linked lists that represent Set A and Set B respectively.
Implement the following function to calculate A U B and return the result as a
new linked list. Note that a SET should not contain duplicate elements
(e.g., integers).

There are two linked lists, LA and LB. Their elements are both in the
non-descending order. Implement the following function to merge LA and LB
into a new linked list (as the return value). The elements in the new list
should still be in the non-descending order.
*/

#include <iostream>
#include <string>

using namespace std;

//linkedlists class declairation


struct Node {
	int data;
	struct Node* next;
};



void insert(struct Node** head, int vals) {

	struct Node* current = (struct Node*)malloc(sizeof(struct Node));

	current->data = vals;
	current->next = *head;

	*head = current;
}



struct Node* unionLL(Node* LA, Node* LB) {

	int calcVal;

	Node* n = LA;
	Node* m = LB;

	struct Node* unionList = NULL;

	while (n != NULL) {
		insert(&unionList, n->data);
		n = n->next;
	}
	while (m != NULL) {
		insert(&unionList, m->data);
		m = m->next;
	}

	return unionList;
}

Node* mergeLL(Node* LA, Node *LB) {

	if (LA == NULL) { return LB; } //if theres nothing in the first list, just print the 2nd list
	if (LB == NULL) { return LA; } //if theres nothing in the second list, just print the 1st one

	if (LA->data < LB->data) {
		//punch the first data in if the number is bigger
		LA->next = mergeLL(LA->next, LB);
		return LA;
	}
	else {
		//punch the second data in if the number is bigger
		LB->next = mergeLL(LA, LB->next);
		return LB;
	}
}

void peekAtlists(Node* n) {
	while (n != NULL) {
		cout << n->data << " -> ";
		n = n->next;
	}
}

int main() {
	int calcVal;

	cout << "This is a program" << endl;

	Node* LA = new Node();
	Node* LB = new Node();
	Node* LC = new Node();
	Node* LLmerge = new Node();

	//LA Stuff
	insert(&LA, 3);
	insert(&LA, 5);
	insert(&LA, 8);
	insert(&LA, 1);
	cout << "\nLA items" << endl;
	peekAtlists(LA);


	insert(&LB, 2);
	insert(&LB, 6);
	insert(&LB, 8);
	insert(&LB, 9);
	insert(&LB, 22);
	insert(&LB, 24);
	cout << "\nLB items" << endl;
	peekAtlists(LB);

	cout << "\nLC items" << endl;
	LC = unionLL(LA, LB);
	peekAtlists(LC);
	
	LLmerge = mergeLL(LA, LB);
	cout << "\nLLmerge items" << endl;
	peekAtlists(LLmerge);

	
	

	return 0;
}



