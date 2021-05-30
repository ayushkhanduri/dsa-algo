//https://leetcode.com/problems/longest-palindromic-substring/
#include"iostream"
#include"string"

using namespace std;

string checkPalindrome( string s ) {
	bool isPalindrome = true;
	int size = s.size();
	for ( int i = 0; i < size / 2 ; i++ ) {
		if ( s[i] != s[size - i - 1]) {
			isPalindrome = false;
		}
	}
	if ( isPalindrome ) {
		return s;
	} else {
		return "";
	}
}



string bruteForce(string s) {
	int size = s.size();
	string longestString = "";
	for ( int i = 0 ; i < size ; i++ ) {
		string localLongest = "";
		for ( int j = i + 1 ; j < size ; j++) {
			localLongest = checkPalindrome( s.substr(i, j));
			if ( localLongest.size() >  longestString.size() ) {
				longestString = localLongest;
			}
		}
	}
	return longestString;
}

int isCachedPalindrome(int **table, int start, int end, string s ) {
	int areBothCharacterEqual = s.at(start) == s.at(end);
	int isPalindrome = (table[start + 1][end - 1] == 1) && areBothCharacterEqual;
	return isPalindrome;
}

string dynamicPalidrome(string s) {
	int size = s.size();
	int **table = new int *[size];
	int largestDiff = 0;
	string largestPalindrome = "";
	if (size == 1) {
		return s;
	}
	for (int i = 0 ; i < size; i++ ) {
		table[i] = new int[size];
		table[i][i] = 1;
	}

	for (int i = 0; i < size; i++) {
		if (s[i] == s[i + 1]) {
			table[i][i + 1] = 1;
			largestDiff = 1;
			largestPalindrome = string(1, s.at(i)) + s.at(i + 1);
		}
	}

	for (int i = 2; i < size ; i++ ) {
		for ( int j = 0; j < size - i; j++ ) {
			int k = i + j ;
			int result = isCachedPalindrome(table, j, k, s);
			table[j][k] = result;
			if ( result == 1 ) {
				int diff = k - j;
				if (diff > largestDiff) {
					largestDiff = diff;
					largestPalindrome = s.substr(j, diff + 1);
				}
			}
		}
	}

	if (largestPalindrome.size() == 0 ) {
		return string(1, s.at(0));
	}
	return largestPalindrome;

}

void leftRightLoop( int &left, int &right, int &longestSize, string &longestPalidrome, string s , int size ) {
	while (left >= 0 && right < size ) {
		if (s.at(left) == s.at(right)) {
			int diff = right - left;
			if (diff > longestSize) {
				longestSize = diff;
				longestPalidrome = s.substr(left, diff + 1);
			}
			left--;
			right++;
		} else {
			break;
		}

	}
}

string withouDP(string s) {
	int size = s.size(), longestSize = 0;
	string longestPalidrome;
	for (int i = 0 ; i < size ; i++) {
		int left = i, right = i + 2;
		leftRightLoop(left, right, longestSize, longestPalidrome, s, size);
		left = i;
		right = i + 1;
		leftRightLoop(left, right, longestSize, longestPalidrome, s, size);
	}

	if (longestPalidrome.size() == 0) {
		return string(1, s.at(0));
	}
	return longestPalidrome;
}

int main() {
	//testpilipt
	//ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy
	string s = "ac";


	cout << withouDP(s);
}
