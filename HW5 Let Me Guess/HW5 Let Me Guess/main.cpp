//Tanner Kvarfordt
//A02052217

#include"LetMeGuess.hpp"
#include<iostream>

int main() {
	std::string keepPlaying = "yes";
	LetMeGuess game;

	std::cout << "Welcome to the Let Me Guess Game!\n\nRules:\n-Answer any yes or no questions with exactly 'yes' or 'no'\n\n";

	while (keepPlaying == "yes" || keepPlaying == "Yes" || keepPlaying == "YES") {
		game.play();
		std::cout << "Do you want to play again?\n";
		std::cin >> keepPlaying;
		std::cout << std::endl;
	}
	game.print();
	
	return EXIT_SUCCESS;
}