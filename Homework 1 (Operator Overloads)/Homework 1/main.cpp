//Tanner Kvarfordt
//A02052217

//This program demonstrates the full functionality of the RatNum class

#include"RatNum.h"
#include<iostream>


int main() {
	//Constructor and simplification tests
	RatNum test(33, 3), test2(7, 16);
	std::cout << "Initial Tests:\n\n";
	std::cout <<"RatNum initialized to (33, 3): " << test << std::endl
		<< "Enter a fraction (a/b): ";
	std::cin >> test;
	std::cout << "Your simplified fraction: " << test << std::endl;
	std::cout<< "Doubling your fraction using +=: " << (test+=test);

	//casting tests
	std::cout << "\n\nCasting Tests:\n\n"
		<< "Double: " << test << " = " << static_cast<double>(test) << std::endl
		<< "Float: " << test << " = " << static_cast<float>(test) << std::endl << std::endl;

	//Arithmatic operator tests
	std::cout << "Arithmatic Operator Tests:\n\n"
		<< "+=:\n"
		<< test << " + " << test2 << " = ";
	std::cout << (test += test2);

	test.resetRatNum(4, 8);
	std::cout << "\n+:\n"
		<< test2 << " + " << test << " = ";
	std::cout << (test2 + test);

	test.resetRatNum(4, 5);
	std::cout << "\n-=:\n"
		<< test2 << " - " << test << " = ";
	std::cout << (test2 -= test);

	std::cout << "\n-:\n"
		<< test2 << " - " << test << " = ";
	std::cout << (test2 - test);

	std::cout << "\n*=:\n"
		<< test2 << " * " << test << " = ";
	std::cout << (test2 *= test);

	std::cout << "\n*:\n"
		<< test2 << " * " << test << " = ";
	std::cout << (test2 * test);

	test2.resetRatNum(6, 7);
	std::cout << "\n/=:\n"
		<< test2 << " / " << test << " = ";
	std::cout << (test2 /= test);

	std::cout << "\n/:\n"
		<< test2 << " / " << test << " = ";
	std::cout << (test2 / test);

	//comparison tests
	std::cout << "\n\nComparison Tests:\n\n";
	RatNum small(1, 8), large(15, 16);

	std::cout << "1/8 < 15/16 Comparison Test: ";
	if (small < large) {
		std::cout << "True - Success!";
	}
	else {
		std::cout << "Failed. :(";
	}

	std::cout << "\n15/16 < 1/8 Comparison Test: ";
	if (large < small) {
		std::cout << "Failed. :(";
	}
	else {
		std::cout << "False - Success!";
	}

	small.resetRatNum(1, 4);
	large.resetRatNum(1, 4);
	std::cout << "\n1/4 = 1/4 Comparison Test: ";
	if (small == large) {
		std::cout << "True - Success!";
	}
	else {
		std::cout << "Failed. :(";
	}

	large.resetRatNum(25, 100);
	std::cout << "\n1/4 = 25/100 Comparison Test: ";
	if (small == large) {
		std::cout << "True - Success!";
	}
	else {
		std::cout << "Failed. :(";
	}

	large.resetRatNum(27, 100);
	std::cout << "\n1/4 = 27/100 Comparison Test: ";
	if (small == large) {
		std::cout << "Failed. :(";
	}
	else {
		std::cout << "False - Success!";
	}

	large.resetRatNum(8, 7);
	small.resetRatNum(24, 100);
	std::cout << "\n8/7 > 24/100 Comparison Test: ";
	if (large > small) {
		std::cout << "True - Success!";
	}
	else {
		std::cout << "Failed. :(";
	}

	std::cout << "\n24/100 <= 8/7 Comparison Test: ";
	if (small <= large) {
		std::cout << "True - Success!";
	}
	else {
		std::cout << "Failed. :(";
	}

	large.resetRatNum(5, 10);
	small.resetRatNum(1, 2);
	std::cout << "\n1/2 <= 5/10 Comparision Test: ";
	if (small <= large) {
		std::cout << "True - Success!";
	}
	else {
		std::cout << "Failed. :(";
	}

	std::cout << "\n1/2 >= 5/10 Comparision Test: ";
	if (small >= large) {
		std::cout << "True - Success!";
	}
	else {
		std::cout << "Failed. :(";
	}

	large.resetRatNum(8, 40);
	small.resetRatNum(4, 50);
	std::cout << "\n4/50 >= 8/40 Comparision Test: ";
	if (small >= large) {
		std::cout << "Failed. :(";
	}
	else {
		std::cout << "False - Success!";
	}

	std::cout << "\n4/50 != 8/40 Comparision Test: ";
	if (small != large) {
		std::cout << "True - Success!";
	}
	else {
		std::cout << "Failed. :(";
	}

	large.resetRatNum(5, 10);
	small.resetRatNum(1, 2);
	std::cout << "\n5/10 != 1/2 Comparision Test: ";
	if (small != large) {
		std::cout << "Failed. :(";
	}
	else {
		std::cout << "False - Success!";
	}

	std::cout << "\n\nRatNum Class Complete!";

	std::cout << std::endl << std::endl;
	return EXIT_SUCCESS;
}