#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


using namespace std;


pair<double, double> calculateIntermediaryServer(pair<double, double> server1,
													pair<double, double> server2) {
	// edge case
	if (server2.first - fabs(server2.second-server1.second) > server1.first) {
	   return server1;
	}
	if (server1.first - fabs(server1.second-server2.second) > server2.first) {
	   return server2;
	}
	if (server2.second > server1.second) {
		double intermediaryCurent = (server1.first - server2.first +
		server1.second + server2.second)/2;
		double intermediaryPower = server1.first -
		fabs(server1.second - intermediaryCurent);
		return make_pair(intermediaryPower, intermediaryCurent);
	}
	if (server2.second <= server1.second) {
		double intermediaryCurent = (-server1.first + server2.first +
		server1.second + server2.second)/2;
		double intermediaryPower = server1.first -
		fabs(server1.second - intermediaryCurent);
		return make_pair(intermediaryPower, intermediaryCurent);
	}
}

int main() {
	std::ofstream outputFile("servere.out");
	std::ifstream inputFile("servere.in");
	int N;
	inputFile >> N;
	vector<double> puteri(N);
	vector<double> curent(N);
	for (int i = 0; i < N; ++i) {
		inputFile >> puteri[i];
	}
	for (int i = 0; i < N; ++i) {
		inputFile >> curent[i];
	}
	vector<pair<double, double>> serverPairs;
	for (int i = 0; i < N; ++i) {
		serverPairs.push_back(make_pair(puteri[i], curent[i]));
	}
	for (int i = 0; i <  N-1; i++) {
		pair<double, double> intermediaryServer =
		calculateIntermediaryServer(serverPairs[i], serverPairs[i+1]);
		serverPairs[i+1] = intermediaryServer;
	}
	outputFile.setf(ios::fixed);
	outputFile.precision(1);
	outputFile << serverPairs[N-1].first << endl;
	outputFile.close();
	return 0;
}
