#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
	// Return the minimum number of characters to make the password strong
	int count = 0;
	int arr[4] = { 0, 0, 0, 0 };

	for (int i = 0; i <= n; i++) {
		//uppercase
		if (int(password[i]) >= 97 && int(password[i]) <= 122) {
			arr[0] = 1;
		}
		//lowercase
		if (int(password[i]) >= 65 && int(password[i]) <= 90) {
			arr[1] = 1;
		}
		//Special Symbols
		if (int(password[i]) >= 33 && int(password[i]) <= 43) {
			arr[2] = 1;
		}
		if (int(password[i]) == 45) {
			arr[2] = 1;
		}
		//numbers
		if (int(password[i]) >= 48 && int(password[i]) <= 57) {
			arr[3] = 1;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (arr[i] == 0) {
			count++;
		}
	}
	if (count < (6 - n)) {
		count = 6 - n;
	}
	return count;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string password;
	getline(cin, password);

	int answer = minimumNumber(n, password);

	fout << answer << "\n";

	fout.close();

	return 0;
}
