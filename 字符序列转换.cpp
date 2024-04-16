#include <iostream>
#include <string>
using namespace std;

int countValidPairs(int L, int R) {
	int validPairs = 0;
	for (int a = L; a <= R; ++a) {
		string strA = to_string(a);
		int lenA = strA.length();
		for (int i = 1; i < lenA; ++i) {
			
			string strB = strA.substr(i) + strA.substr(0, i);
			int b = stoi(strB);
			
			if (a < b && b <= R) {
				validPairs++;
			}
		}
	}
	return validPairs;
}

int main() {
	int L, R;
	cin >> L >> R;
	
	cout << countValidPairs(L, R) << endl;
	return 0;
}
