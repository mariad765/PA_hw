#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#include <queue>
#include <unordered_map>
bool isDominant(const string& passwd, char letter) {
	int count = 0;
	for (char c : passwd) {
		if (c == letter) {
			count++;
		}
	}
	return count > passwd.size() / 2;
}

// Funcție pentru a calcula lungimea maximă a
// parolei care îndeplinește condițiile date
int maxPasswordLength(int N, const vector<string>& words) {
	int maxLength = 0;
	// afla cele 8 litere
	set<char> letters;
	for (const string& word : words) {
		for (char letter : word) {
			letters.insert(letter);
		}
	}
	// pt fiecare litera, se va retine numarul de aparitii pentru
	// fiecare cuvant in perechi : numar aparitii, numar litere cuvant
	unordered_map<char, vector<pair<int, int>>> letterCounts;
	for (char letter : letters) {
		for (const string& word : words) {
			int count = 0;
			for (char c : word) {
				if (c == letter) {
					count++;
				}
			}
			letterCounts[letter].push_back({count, word.size()});
		}
	}
	// vectorul de va ordona descrescator dupa raportul aparitii/numar litere
	for (auto& [letter, counts] : letterCounts) {
		sort(counts.begin(), counts.end(), [](const pair<int, int>& a,
												const pair<int, int>& b) {
			return (double)a.first / a.second > (double)b.first / b.second;
		});
	}
	// print the letters and the vector of pairs sorted
	for (char letter : letters) {
		cout << letter << ": ";
		for (const auto& [c, l] : letterCounts[letter]) {
			cout << c << "/" << l << " ";
		}
		cout << '\n';
	}
	// pentru fiecare litera se va genera cate o parola cu
	// dimensiune maxima astfel:
	// se va lua prima pereche din vector si se vor aduna progresiv
	// aparitiile si literele cuvantului
	// daca perechea nou obtinuta nu este dominanta se opreste
	// sti dimentiunea maxima aia este
	for (char letter : letters) {
		int count = 0;
		int length = 0;
		for (const auto& [c, l] : letterCounts[letter]) {
			// show c and l
			 cout << c << " " << l << '\n';
			if (count + c > static_cast<double>((length + l) / 2.0)) {
				count += c;
				length += l;
			} else {
			   // try with the next pair
			   continue;
			}
			// show every length calculated
			 cout << letter << ": " << length << '\n';
		}
		// show max length for each letter
	   //  cout << letter << ": " << length << '\n';
		maxLength = max(maxLength, length);
	}
	return maxLength;
}
// write a main in cpp
int main() {
	std::ifstream inputFile("criptat.in");  // Deschidem fișierul de intrare
	std::ofstream outputFile("criptat.out");  // Deschidem fișierul de ieșire
	// read number of words
	int N;
	inputFile >> N;
	// read words
	std::vector<std::string> words(N);
	for (int i = 0; i < N; ++i) {
		inputFile >> words[i];
	}
	int maxLength = maxPasswordLength(N, words);
	outputFile << maxLength << '\n';
	cout << maxLength << '\n';
	// close files
	inputFile.close();
	outputFile.close();

return 0;
}
