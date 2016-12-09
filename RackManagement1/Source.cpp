#include <iostream>
#include <sstream>
#include <string>

bool scrabble(std::string tiles, std::string targetWord) {
	
	// loop each letter in targetWord
	for (int i = 0; i < targetWord.length; i++) {

		// if the letter matches a tile, remove the tile from the tray and continue
		if (tiles.find(targetWord[i]) != std::string::npos) {
			int tilePosition = tiles.find(targetWord[i]);

			tiles = tiles.substr(0, tilePosition - 1) + tiles.substr(tilePosition + 1, tiles.length);
		}
		// else we require a tile we don't have, return false
		else {
			return false;
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
}