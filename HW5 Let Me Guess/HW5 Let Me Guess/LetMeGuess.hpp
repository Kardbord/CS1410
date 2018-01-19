#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include<iostream>
#include<memory>
#include<string>
#include<fstream>

struct TreeNode {
	std::string question;
	TreeNode(std::string d, std::shared_ptr<TreeNode> y = nullptr, std::shared_ptr<TreeNode> n = nullptr) :question(d), yes(y), no(n) {}
	virtual std::shared_ptr<TreeNode> process() = 0; // = 0 makes this a pure virtual function
	virtual void print(std::ofstream &) = 0;
	std::shared_ptr<TreeNode> yes;
	std::shared_ptr<TreeNode> no;
};

struct QuestionNode :TreeNode {
	QuestionNode(std::string q, std::shared_ptr<TreeNode> y = nullptr, std::shared_ptr<TreeNode> n = nullptr) :TreeNode(q, y, n) {}

	void print(std::ofstream & f) override {
		f << question << std::endl << 1 << std::endl;
		yes->print(f);
		no->print(f);
	}

	std::shared_ptr<TreeNode> process() override {
		std::string answer;
		std::cout << question << std::endl;
		std::cin >> answer;
		std::cout << std::endl;
		std::cin.ignore();

		if (answer == "no" || answer == "No" || answer == "NO" || answer == "n" || answer == "N") {
			no = no->process();
		}
		else {
			yes = yes->process();
		}
		return std::make_shared<QuestionNode>(question, yes, no);
	}
};

struct AnswerNode :TreeNode {
	AnswerNode(std::string q) :TreeNode(q) {}

	void print(std::ofstream & f) override {
		f << question << std::endl << 0 << std::endl;
	}

	std::shared_ptr<TreeNode> process() override {
		std::string answer;
		std::string newQuestion;
		std::cout << question << std::endl;
		std::cin >> answer;
		std::cout << std::endl;
		std::cin.ignore();

		if (answer == "no" || answer == "No" || answer == "NO") {
			std::cout << "What were you thinking of?\n";
			std::getline(std::cin, answer);
			std::cout << "\nWhat could I have asked to help me get to that answer?\n";
			std::getline(std::cin, newQuestion);
			std::cout << std::endl;
			std::string newAnswer = "Are you thinking of " + answer + '?';

			return std::make_shared<QuestionNode>(newQuestion, std::make_shared<AnswerNode>(newAnswer), std::make_shared<AnswerNode>(question));
		}
		else {
			std::cout << "I win. ";
			return std::make_shared<AnswerNode>(question);
		}
	}
};



class LetMeGuess {
public:
	LetMeGuess() { setUp(); }

	void play() {
		root->process();
	}

	void print() {
		std::ofstream fout("knowledgeBase.txt");
		root->print(fout);
		fout.close();
	}

private:
	std::shared_ptr<TreeNode> root;
	
	void read(std::ifstream &, std::shared_ptr<TreeNode> &);

	void setUp() {
		std::ifstream fin("knowledgeBase.txt");
		if (fin.fail()) {
			std::cout << "\a\nWarning! Could not open knowledge base. Program will require training.\n\n";

			root = std::make_shared<QuestionNode>("Are you thinking of a person?");
			root->yes = std::make_shared<AnswerNode>("Are you thinking of Adam Sandler?");

			root->no = std::make_shared<QuestionNode>("Are you thinking of a place?");
			root->no->yes = std::make_shared<AnswerNode>("Are you thinking of Istanbul?");

			root->no->no = std::make_shared<QuestionNode>("Are you thinking of a plant?");
			root->no->no->yes = std::make_shared<AnswerNode>("Are you thinking of marigolds?");

			root->no->no->no = std::make_shared<QuestionNode>("Are you thinking of an animal?");
			root->no->no->no->yes = std::make_shared<AnswerNode>("Are you thinking of a lion?");

			root->no->no->no->no = std::make_shared<QuestionNode>("Are you thinking of a mineral?");
			root->no->no->no->no->yes = std::make_shared<AnswerNode>("Are you thinking of quartz?");

			root->no->no->no->no->no = std::make_shared<QuestionNode>("Are you thinking of a thing?");
			root->no->no->no->no->no->yes = std::make_shared<AnswerNode>("Are you thinking of a toaster?");

			root->no->no->no->no->no->no = std::make_shared<AnswerNode>("Are you thinking of nothing?");
		}
		else {
			read(fin, root);
		}
		fin.close();
	}
};

void LetMeGuess::read(std::ifstream & f, std::shared_ptr<TreeNode> & cur) {
	std::string curQuestion;
	int QvsA;
	std::getline(f, curQuestion);
	f >> QvsA; //a 1 indicates a question node and a 0 indicates an answer node
	f.ignore();
	if (QvsA == 1) {
		cur = std::make_shared<QuestionNode>(curQuestion);
		read(f, cur->yes);
		read(f, cur->no);
	}
	else if (QvsA == 0) {
		cur = std::make_shared<AnswerNode>(curQuestion);
	}
}

#endif
