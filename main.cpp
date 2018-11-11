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
	int arr[10] = {0, 1, 2, 3, 4, 5, 6 ,7 ,8 ,9};
	List list;
	List arr_list(arr, 10);

	arr_list.print();

	return 0;	
}