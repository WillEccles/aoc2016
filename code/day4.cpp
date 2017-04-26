#include <iostream> // duh
#include <vector> // std::vector
#include <fstream> // std::ifstream
#include <string> // std::string
#include <set> // std::set
#include <map> // std::map
#include <algorithm> // std::sort
#include <utility> // std::pair

// returns a string containing the top 5 chars in the given string
// ties are handled alphabetically, i.e. 5 a's and 5 b's would be ba
std::string top5(std::string str) {
	std::map<char, int> letters;
	
	// fill the map with default values
	for (char l = 'a'; l <= 'z'; l++)
		letters[l] = 0;

	// now we go through the string and count each letter
	for (char c: str)
		if (c != '-') letters[c]++;
	
	std::map<int, std::set<char, std::less<char>>, std::greater<int>> lettercounts;
	for (auto& p: letters) {
		if (p.second != 0) {
			lettercounts[p.second].insert(p.first);
		}
	}

	std::string result("");

	for (auto& p: lettercounts) {
		for (auto& x: p.second) {
			result += x;
		}
	}

	return result.substr(0, 5);
}

int main(void) {
	std::ifstream file("../input/day4.txt");
	std::string name;
	int id;
	std::string checksum;
	std::vector<std::string> names;
	std::vector<int> ids;
	std::vector<std::string> checksums;

	// read every line of input and store the name and checksum
	// i have the input formatted as "aaaaaa-a-a-a-a 123 checksum", where checksum does not have the [] around it
	while (file >> name >> id >> checksum) {
		names.push_back(name);
		ids.push_back(id);
		checksums.push_back(checksum);
	}

	file.close();
	
	int sum = 0; // sum of ids

	for (int i = 0; i < names.size(); i++) {
		if (top5(names[i]) == checksums[i])
			sum += ids[i];
	}

	std::cout << "sum: " << sum << '\n';
}
