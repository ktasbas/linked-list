// M. Kaan Tasbas | mktasbas@gmail.com
// November 2018

/**
 * Simple linked list class to practice various coding concepts
 **/

#include <iostream>

struct Node{
	int data;
	Node* next;

	Node(){
		data = -1;
		next = nullptr;
	}

	Node(int data){
		this->data = data;
		next = nullptr;
	}

	Node(Node* copy){
		this->data = copy->data;
		this->next = copy->next;
	}
};

class List{
	public:
	
	// constructor
	List(){
		this->head = nullptr;
	}

	// constructor - array to list
	List(int* arr, int size){
		// initialize head node
		head = new Node(arr[0]);

		// use current pointer to traverse
		Node* current = head;

		for(int i = 1; i < size; i++)
		{
			current->next = new Node(arr[i]);
			current = current->next;
		}
	}

	// destructor
	~List(){
		//check if list is empty
		if(this->isEmpty()) return;
		// begin at the head of list
		Node* current = this->head;
		// iterate list
		while(current->next != nullptr)
		{
			// save pointer to next node
			Node* next = current->next;
			// delete current node
			delete current;
			// move to next node
			current = next;
		}
		// now current = last node
		// delete final node
		delete current;
	}

	void addNode(Node* node){
		// TODO: duplicate node instead to avoid errors with deleted pointers

		// check if list is empty
		// point head to node if it is]
		if(this->isEmpty())
		{
			head = node;
			return;
		}
		// traverse to last element in list
		Node* current = head;
		while(current->next != nullptr)
		{
			current = current->next;
		}
		// add element
		current->next = node;
		// TODO: should node->next be set to null?
		// what if it points to a next node already?
	}

	bool isEmpty(void){
		if (this->head == nullptr) return true;
		else return false;
	}

	void print(void){
		Node* current = head;

		while(current != nullptr)
		{
			std::cout << current->data << " -> ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	private:

	Node* head;
};

int main()
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6 ,7 ,8 ,9};	// array to test constructor
	List empty_list;		// default constructor
	List test_list(arr, 10);	// array to list constructor

	Node *test_node = new Node(10);		// node to test with
	test_list.addNode(test_node);		// test addNode function

	test_list.print();

	return 0;	
}