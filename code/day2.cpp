#include <iostream>
#include <fstream>
#include <string>

int main(void) {
	std::string inputFile("../input/day2.txt");
	std::ifstream file(inputFile);

	// this is the keypad (you start on 5)
	int keyPad[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int col = 1; // second column
	int row = 1; // second row
	
	std::string code = "";

	std::string line;
	while (std::getline(file, line)) {
		for (auto c : line) {
			switch (c) {
				case 'U':
					if (row > 0) row--;
					break;
				case 'D':
					if (row < 2) row++;
					break;
				case 'L':
					if (col > 0) col--;
					break;
				case 'R':
					if (col < 2) col++;
					break;
			}
		}

		code += std::to_string(keyPad[row][col]);
	}

	std::cout << "Keycode: " << code << std::endl;

	return 0;
}
