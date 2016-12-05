#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

int main(void) {
	std::string inputFile = "../input/day1.txt";
	std::fstream file(inputFile);
	
	int heading = 0; // North
	int distX = 0;
	int distY = 0;

	char dir;
	int dist;
	while (file >> dir >> dist) {
		if (dir == 'R') {
			if (heading < 270)
				heading += 90;
			else heading = 0;
		} else if (dir == 'L') {
			if (heading > 0)
				heading -= 90;
			else heading = 270;
		}
		
		switch (heading) {
			case 0:
				distY += dist;
				break;
			case 90:
				distX += dist;
				break;
			case 180:
				distY -= dist;
				break;
			case 270:
				distX -= dist;
				break;
		}
	}

	// figure out the total distance
	int distTotal = std::abs(distX) + std::abs(distY);
	std::cout << "Distance: " << distTotal << std::endl;

	return 0;
}
