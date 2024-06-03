#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <set>
#include <map>

using namespace std;

double my_min(double a, double b) {
	return (a < b) ? a : b;
}
double my_max(double a, double b) {
	return (a > b) ? a : b;
}

double min_shopping_price(vector<int> costuri, int N) {
	// initializam vectorul de costuri
	// vom folosi programare dinamica pentru a calcula costul minim
	vector<double> dp(N+1, INT_MAX);
	// cazul de baza
	dp[0] = 0;
	// cazul general
	for (int i = 1; i <= N; ++i) {
		// calculam costul minim pentru fiecare i
		dp[i] = my_min(dp[i], costuri[i-1] + (i >= 1 ? dp[i-1] : 0));
		// cazuri speciale
		if (i >= 2) {
			// sortam costurile pentru a lua cate 2
			double cost = my_max(costuri[i-1], costuri[i-2]) + 0.5 *
			min(costuri[i-1], costuri[i-2]);
			dp[i] = my_min(dp[i], cost + dp[i-2]);
		}
		if (i >= 3) {
			// sortam costurile pentru a lua cate 3
			vector<int> vect_for_trei = {costuri[i-1], costuri[i-2], costuri[i-3]};
			sort(vect_for_trei.begin(), vect_for_trei.end());
			// calculam costul minim pentru a lua 3 produse
			double cost = vect_for_trei[2] + vect_for_trei[1];
			// adaugam costul la dp[i-3]
			dp[i] = my_min(dp[i], cost + dp[i-3]);
		}
	}
	// returnam costul minim pentru a cumpara N produse
	return dp[N];
}



int main() {
	ifstream inputFile("oferta.in");
	ofstream outputFile("oferta.out");
	int N, K;
	inputFile >> N >> K;
	 vector<int> costuri(N);
	for (int i = 0; i < N; ++i) {
		inputFile >> costuri[i];
	}
	double min_price = min_shopping_price(costuri, N);
	// setam precizia la 1 zecimala
	outputFile.precision(1);
	// scriem ca output costul minim
	outputFile << fixed;
	outputFile << min_price;
	// close files
	inputFile.close();
	outputFile.close();
	return 0;
}
