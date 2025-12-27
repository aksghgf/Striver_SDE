Problem Link: https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_8230827?challengeSlug=striver-sde-challenge&leftPanelTab=0

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* down, Node* right) {

	Node* dummy = new Node(-1);
	Node* temp = dummy;

	while (down && right) {
		if (down->data < right->data) {
			temp->child = down;
			temp = down;
			down = down->child;
		}
		else {
			temp->child = right;
			temp = right;
			right = right->child;
		}
	} 

	while (down) {
		temp->child = down;
		temp = down;
		down = down->child;
	}

	while (right) {
		temp->child = right;
		temp = right;
		right = right->child;
	}
	
	dummy = dummy->child;
	return dummy;
}


Node* flattenLinkedList(Node* head) 
{
	if (head->next == NULL) return head;
	
	Node* down = head;
	
	Node* right = flattenLinkedList(head->next);
	down->next = NULL;

	Node* ans = merge(down, right);
	return ans;
	
}

