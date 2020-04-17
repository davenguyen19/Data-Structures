#include <bits/stdc++.h>
#include string;

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
	bool ok = true;

	while (ok && s.size()>1) {
		ok = false;
		for (int i = 1; i<s.size(); i++) {
			if (s[i] == s[i - 1]) {
				s = s.substr(0, i - 1) + s.substr(i + 1);
				ok = true;
			}
		}
	}

	if (s.size() == 0) {
		s = "Empty String\n";
	}

	return s;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string s;
	getline(cin, s);

	string result = superReducedString(s);

	fout << result << "\n";

	fout.close();

	return 0;
}
