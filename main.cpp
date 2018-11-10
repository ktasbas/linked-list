// M. Kaan Tasbas | mktasbas@gmail.com
// November 2018

/**
 * Simple linked list class to practice various coding concepts
 **/

struct Node{
	int data;
	Node* next;
};

class List{
	public:
	
	// constructor
	List(){
		this->head = nullptr;
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

	private:

	Node* head;
};

int main()
{
	List list;
	return 0;	
}