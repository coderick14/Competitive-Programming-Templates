#include <bits/stdc++.h>
using namespace std;

string getPaddedString(const string& s, string delim = "#") {
	string paddedString = "#";
	for (const char& c : s) {
		paddedString += c;
		paddedString += delim;
	}
	return paddedString;
}

long getMaxPos(const vector<long>& span) {
	long maxlen = 1, pos = 1, n = span.size();
	for (long i = 2; i < n; i++) {
		if (span[i] > maxlen) {
			maxlen = span[i];
			pos = i;
		}
	}
	return pos;
}

string getUnpaddedString(const string& s, const long& maxPos, const long& maxlen) {
	string ans;
	long start = maxPos - maxlen + 1, end = maxPos + maxlen - 1;
	for (long i = start; i <= end; i++) {
		if (s[i] != '#') ans += s[i];
	}
	return ans;
}

string manacher(const string& s) {
	string str = getPaddedString(s);
	long n = str.length();
	vector<long> span(n,1);
	long c = 0, r = 0;
	for (long i = 1; i < n; i++) {
		if (i <= r and 2*c - i >= 0) {
			span[i] = min(r - i + 1, span[2*c - i]);
		}
		while (i - span[i] >= 0 and i + span[i] < n and str[i - span[i]] == str[i+span[i]]) span[i]++;
		if (i + span[i] - 1 > r) {
			c = i;
			r = i + span[i] - 1;
		}
	}
	long maxPos = getMaxPos(span);
	long maxlen = span[maxPos];
	return getUnpaddedString(str, maxPos, maxlen);
}

int main() {
	string s;
	cin >> s;
	cout << manacher(s) << endl;
	return 0;
}
