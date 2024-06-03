#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// pow cu shiftare pe boiti sa fie mai rapid
long long modPow(long long base, int exp, int modd) {
	long long result = 1;
	base %= modd;
	while (exp > 0) {
		if (exp & 1) {
			result = (result * base) % modd;
		}
		base = (base * base) % modd;
		exp >>= 1;
	}
	return result;
}



long long numarModeleDistincte(pair<int, string> regiunePrev,
								pair<int, string> regiuneCurr, long long posibilitati) {
	// verificam piesa precedenta si piesa actuala
		// piesa precedenta e V si urmeaza o piesa tot V
		if (regiunePrev.second == "V") {
			if (regiuneCurr.second == "V")  {
				posibilitati = (posibilitati << 1) % MOD;
				posibilitati = (posibilitati * modPow(2, regiuneCurr.first - 1, MOD)) % MOD;
			} else {
				posibilitati = (posibilitati << 1) % MOD;
				posibilitati = (posibilitati * modPow(3, regiuneCurr.first - 1, MOD)) % MOD;
			}
		}
		  // piesa precedenta e H si urmeaza o piesa V
		 if (regiunePrev.second == "H") {
			if (regiuneCurr.second == "V") {
				posibilitati = (posibilitati *
				modPow(2, regiuneCurr.first - 1, MOD)) % MOD;
			} else {
				posibilitati = ((posibilitati << 1) + posibilitati) % MOD;
				 posibilitati = (posibilitati *
				 modPow(3, regiuneCurr.first - 1, MOD)) % MOD;
			}
		}
return posibilitati;
}

int main() {
	// Open a file named "output.txt" for writing
	std::ofstream outputFile("colorare.out");
	ifstream inputFile("colorare.in");
	// read K from file
	int K;
	inputFile >> K;
	vector<pair<int, string>> regiuni(K);
	int X0;
	string T0;
	inputFile >> X0 >> T0;
	regiuni[0] = {X0, T0};
	long long posibilitati = 1;
	// verificam prima piesa
	if (regiuni[0].second == "V") {
		   posibilitati = ((posibilitati << 1) + posibilitati) % MOD;
		   posibilitati = (posibilitati *
		   modPow(2, regiuni[0].first - 1, MOD)) % MOD;
	} else {
		   posibilitati = (posibilitati * 6) % MOD;
		for (int i = 1; i < regiuni[0].first; i++) {
			posibilitati = ((posibilitati << 1) + posibilitati) % MOD;
		}
	}
	for (int i = 1; i < K; i++) {
		int X;
		string T;
		inputFile >> X >> T;
		regiuni[i] = {X, T};
		posibilitati = numarModeleDistincte(regiuni[i-1], regiuni[i], posibilitati);
	}
	// write rezultat to file
	outputFile << posibilitati << std::endl;
	inputFile.close();
	outputFile.close();
	return 0;
}
