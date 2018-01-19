#include<iostream>
#include"linkedList.h"

template<typename T>
void print(T const &);

LinkedList<int> RHS();

int main() {
	LinkedList<int> test;
	std::cout << "\t\t\t\tInitial Tests:\n\n";
	test.insert(46);
	test.insert(51);
	test.insert(42);
	test.insert(7);
	test.insert(76);
	test.insert(38);
	test.insert(4);
	test.insert(77);
	test.insert(77);
	test.insert(42);
	test.insert(25);
	test.insert(4);
	test.insert(25);
	test.insert(77);
	test.insert(12);
	test.insert(6);
	std::cout << "Linked List 'test': ";
	test.forEach(print<int>);
	std::cout << std::endl;
	std::cout << "Size of List: " << test.size() << std::endl << std::endl;

	std::cout << "\t\t\t      [] Overload Tests:\n";
	std::cout << std::endl << "test[0] = " << test[0];
	std::cout << std::endl << "test[1] = " << test[1];
	std::cout << std::endl << "test[2] = " << test[2];
	std::cout << std::endl << "test[5] = " << test[5];
	std::cout << std::endl << "test[7] = " << test[7];
	std::cout << std::endl << "test[500] = " << test[500];

	std::cout << "\n\t\t\t    Remove Function Tests:";
	std::cout << std::endl << std::endl;
	test.remove(4);
	std::cout << "Remove Function Test (Beg. of List): ";
	test.forEach(print<int>);
	std::cout << std::endl << "Size of List: " << test.size();

	std::cout << std::endl << std::endl;
	test.remove(25);
	std::cout << "Remove Function Test (Middle of List): ";
	test.forEach(print<int>);
	std::cout << std::endl << "Size of List: " << test.size();

	std::cout << std::endl << std::endl;
	test.remove(77);
	std::cout << "Remove Function Test (End of List): ";
	test.forEach(print<int>);
	std::cout << std::endl << "Size of List: " << test.size();

	std::cout << "\n\n\n\t\t      Constructor and Assignment Tests:\n\n";
	LinkedList<int> newTest(test); //debug for proof that this is a deep copy - breakpoints here and at deep copy constructor and *optional* the two clone functions in linkedList.h (last bit is more for my benefit than yours, grader :) )
	std::cout << "Constructor created 'newTest': ";
	newTest.forEach(print<int>);
	std::cout << std::endl;
	std::cout << "Size of List: " << newTest.size() << std::endl << std::endl;
	newTest.remove(46);
	std::cout << "'newTest' after newTest.remove(46): ";
	newTest.forEach(print<int>);
	std::cout << std::endl;
	std::cout << "Size of List: " << newTest.size() << std::endl << std::endl;
	std::cout << "Proof of existence of initial 'test': ";
	test.forEach(print<int>);
	std::cout << std::endl << "Size of List: " << test.size();
	test = newTest; //debug for proof that this is a deep copy
	std::cout << "\n\n'test' after test = newTest: ";
	test.forEach(print<int>);
	std::cout << std::endl << "Size of List: " << test.size();

	std::cout << "\n\nMove Construction Test: ";
	LinkedList<int> test3(RHS()); //debug for proof that this is a shallow copy - breakpoints here and at shallow move constructor in linkedList.h 
	test3.forEach(print<int>);
	std::cout << std::endl;
	std::cout << "Size of List: " << test3.size();

	std::cout << "\n\nMove Assignment Test: ";
	LinkedList<int> test4 = RHS(); //debug for proof that this is a shallow copy 
	test4.forEach(print<int>);
	std::cout << std::endl;
	std::cout << "Size of List: " << test4.size();

	std::cout << std::endl;
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

template<typename T>
void print(T const & t) {
	std::cout << t << ' ';
}

LinkedList<int> RHS() { //for creating an R value
	LinkedList<int> asdf;
	asdf.insert(10);
	asdf.insert(10);
	asdf.insert(10);
	asdf.insert(10);
	asdf.insert(10);
	asdf.insert(10);
	asdf.insert(10);
	return asdf;
}