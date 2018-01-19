#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<memory>
#include<functional>

template<typename T>
class LinkedList {
public:
	//constructors
	LinkedList() :head(nullptr) {} //default constructor
	LinkedList(LinkedList const && original) :head(original.head) {} //shallow move constructor
	LinkedList(LinkedList const & original) :head(clone(original.head, nullptr)) {} //deep copy constructor

	//member functions
	void insert(T);
	void remove(T target);
	void forEach(std::function<void(T const &)>) const;
	int size() const;

	//operator overloads
	T operator[](int);
	void operator=(LinkedList const &);
	void operator=(LinkedList const &&);

private:
	struct Node {
		T data;
		std::shared_ptr<Node> next; //declaring a variable next of type shared_ptr that points to a Node struct
		std::weak_ptr<Node> prev;
		//constructor
		Node(T newdata, std::shared_ptr<Node> next, std::shared_ptr<Node> prev) :data(newdata), next(next), prev(prev) {}
	};
	std::shared_ptr<Node> head;

	//I need this clone overload for the first time through a deep copy (sending a nullptr)
	std::shared_ptr<Node> clone(std::shared_ptr<Node> list, std::shared_ptr<Node> firstRun) {
		if (!list) return nullptr;
		auto node = std::make_shared<Node>(0, nullptr, nullptr); //Could always write a default constructor for Node... nah
		node->data = list->data;
		node->prev = firstRun;
		std::weak_ptr<Node> copy = node;
		node->next = clone(list->next, copy);
		return node;
	}

	std::shared_ptr<Node> clone(std::shared_ptr<Node> list, std::weak_ptr<Node> prev) {
		if (!list) return nullptr;
		auto node = std::make_shared<Node>(0, nullptr, nullptr);
		node->data = list->data;
		node->prev = prev;
		std::weak_ptr<Node> copy = node;
		node->next = clone(list->next, copy);
		return node;
	}
};


// Function Definitions

template<typename T>
T LinkedList<T>::operator[](int index) {
	auto cur = head;
	std::shared_ptr<Node> temp = nullptr; // a pointer to keep track of cur's last location
	for (auto j = 0; j < index; j++) { //loop until we reach the index we want
		if (!cur) { return T(); }
		temp = cur;
		cur = cur->next; //cur is now equal to the 'next' pointer in the node we're looping through
	}
	if (cur == nullptr) {
		return temp->data;
	}
	return cur->data; //return the data from our desired index
}

template<typename T>
void LinkedList<T>::operator=(LinkedList const & newList) {
	head = clone(newList.head, nullptr);
}

template<typename T>
void LinkedList<T>::operator=(LinkedList const && newList) {
	head = newList.head;
}


template<typename T>
int LinkedList<T>::size() const {
	if (!head) return 0;
	auto cur = head;
	auto count = 0;
	while (cur != nullptr) {
		cur = cur->next;
		count++;
	}
	return count;
}


template<typename T>
void LinkedList<T>::insert(T newElement) {
	if (!head) {
		head = std::make_shared<Node>(newElement, nullptr, nullptr);
		return;
	}

	auto cur = head;
	std::shared_ptr<Node> temp = nullptr;
	while (cur != nullptr && newElement > cur->data) {
		temp = cur;
		cur = cur->next;
	}
	if (temp == nullptr) {
		head = std::make_shared<Node>(newElement, cur, nullptr);
	}
	else {
		temp->next = std::make_shared<Node>(newElement, temp->next, temp);
	}
}


template<typename T>
void LinkedList<T>::forEach(std::function<void(T const &)> function) const {
	for (auto cur = head; cur != nullptr; cur = cur->next) {
		function(cur->data);
	}
}


template<typename T>
void LinkedList<T>::remove(T target) {
	auto cur = head;
	std::shared_ptr<Node> temp = nullptr;
	bool hasSwapped = false;
	while (cur != nullptr) {
		if (cur->data == target) {
			if (temp == nullptr) {
				head = cur->next;
			}
			if (cur->next != nullptr) {
				cur->next->prev = temp;
			}
			if (temp != nullptr) {
				temp->next = cur->next;
			}
			hasSwapped = true;
		}
		if (hasSwapped && temp == nullptr) {
			cur = head;
			hasSwapped = false;
		}
		else if (hasSwapped) {
			cur = cur->next;
			hasSwapped = false;
		}
		else {
			temp = cur;
			cur = cur->next;
		}
	}


}

#endif