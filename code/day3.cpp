#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

int main(void) {
	std::string fileName = "../input/day3.txt";
	std::ifstream file(fileName);

	std::vector<int> triangle(3); // store each triangle
	int count = 0;

	while (file >> triangle[0] >> triangle[1] >> triangle[2]) {
		std::sort(triangle.begin(), triangle.end());
		if (triangle[0] + triangle[1] > triangle[2])
			count++;
	}
	std::cout << count << " real triangles." << std::endl;

	return 0;
}
