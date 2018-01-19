#include"RatNum.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<functional>
#include<exception>

//Prototypes
template<typename F>
void op(F, std::vector<RatNum> &);

int main() {
	std::vector<RatNum> stack;
	std::string entry;
	RatNum temp;

	std::cout << "\t\t\t   Reverse Polish Calculator\n"
		<< "\t\t\t\t   Version 1.1\n\n";
	std::cout << "Supported Functionality:\n"
		<< "\t+ to add\n"
		<< "\t- to subtract\n"
		<< "\t* to multiply\n"
		<< "\t/ to divide\n"
		<< "\tc to clear\n"
		<< "\te to exit\n\n";
	std::cout << "As of version 1.1, all input values must be fractions or whole integers.\n";
	std::cout << "All values and operators must be separated by new lines.\n";
	std::cout << "Values will remain in the stack (even after operations) unless cleared with the c command.\n\n";
	std::cout << "Begin Calculating:\n";

	while (true) {
		std::getline(std::cin, entry);
		std::stringstream sStream(entry);
		try {
			switch (entry[0]) {
			case 'e':
				std::cout << "\nShutting down...\n\n";
				return EXIT_SUCCESS;
				break; //putting "break" here because it pleases me

			case 'c': stack.clear(); std::cout << "\nStack Cleared\n"; break;

			case '+': op(std::plus<RatNum>(), stack);
				std::cout << " = " << stack.back() << std::endl << std::endl;
				break;

			case '-':
				if (entry.size() > 1) {
					sStream >> temp;
					stack.push_back(temp);
					break;
				}
				op(std::minus<RatNum>(), stack);
				std::cout << " = " << stack.back() << std::endl << std::endl;
				break;

			case '*': op(std::multiplies<RatNum>(), stack);
				std::cout << " = " << stack.back() << std::endl << std::endl;
				break;

			case '/': op(std::divides<RatNum>(), stack);
				std::cout << " = " << stack.back() << std::endl << std::endl;
				break;

			default:
				sStream >> temp;
				stack.push_back(temp);
			}
		}
		catch (std::exception & e) {
			std::cout << e.what();
		}
	}
}

template<typename F>
void op(F operation, std::vector<RatNum> & stack) {
	if (stack.size() < 2) {
		throw std::domain_error("\nCannot perform operation: less than two elements on stack\n");
	}
	auto second = stack.back();
	stack.pop_back();
	auto first = stack.back();
	stack.pop_back();
	stack.push_back(operation(first, second));
}