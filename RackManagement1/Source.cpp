#include <iostream>
#include <sstream>
#include <string>

bool scrabble(std::string tiles, std::string targetWord) {
	
	// loop each letter in targetWord
	for (int i = 0; i < targetWord.length(); i++) {
		int tilePosition;

		// if the letter matches a tile, set tilePosition to its location
		if (tiles.find(targetWord[i]) != std::string::npos) {
			tilePosition = tiles.find(targetWord[i]);
		}

		// else set tilePosition to the location of a blank
		else if (tiles.find("?") != std::string::npos) {
			tilePosition = tiles.find("?");
		}

		// else we require a tile we don't have, return false
		else {
			return false;
		}

		// remove the matching tile from the tray
		if (tilePosition == 0) {
			tiles = tiles.substr(tilePosition + 1, tiles.length());
		}
		else {
			tiles = tiles.substr(0, tilePosition - 1) + tiles.substr(tilePosition + 1, tiles.length());
		}
	}
	
	// if the loop completes, we have every tile we need; return true
	return true;
}


int main() {
	std::string myWord;
	std::string myTiles;

	std::cout << "Enter target word" << std::endl;
	std::getline(std::cin, myWord);

	std::cout << "Enter tiles" << std::endl;
	std::getline(std::cin, myTiles);

	if (scrabble(myTiles, myWord) == false) {
		std::cout << "You cannot make '" << myWord << "'" << std::endl;
	}
	else {
		std::cout << "You can make '" << myWord << "'" << std::endl;
	}

	return 1;
}