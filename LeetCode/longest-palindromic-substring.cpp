//https://leetcode.com/problems/longest-palindromic-substring/
#include"iostream"
#include"string"

using namespace std;

string checkPalindrome( string s ) {
	bool isPalindrome = true;
	int size = s.size();
	for ( int i = 0; i< size/2 ; i++ ) {
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
	cout << "Hellow";
    for ( int i = 0 ; i< size ; i++ ) {
			string localLongest = "";
			for ( int j = i+1 ;j < size ; j++) {
				localLongest = checkPalindrome( s.substr(i, j));
				if ( localLongest.size() >  longestString.size() ) {
					longestString = localLongest;
				}
			}
	}
	return longestString;
}

int isCachedPalindrome(int **table, int start, int end, string s ) {
    int areBothCharacterEqual = s[start] == s[end];
    int isPalindrome = (table[start][end-1] == 1) & areBothCharacterEqual;
    return isPalindrome;
}	

string dynamicPalidrome(string s){
	int size = s.size();
	int **table = new int *[size];
	int largestDiff = 0;
	string largestPalindrome = "";
	for (int i = 0 ;i< size;i++ ) {
		table[i] = new int[size];
		table[i][i] = 1;
	}

    for (int i= 0; i<size; i++) {
       if (s[i] == s[i+1]) {
           table[i][i+1]=1;
           largestDiff = 2;
       }
    }

   	for(int i =0; i<size-1; i++ ) {
        for( int j = i+1 ; j< size; j++ ) {
            int result = isCachedPalindrome(table, i, j, s);
            cout<<result; 
            table[i][j] = result;
			if ( result == 1 ) {
                int diff = j - i;
                if (diff > largestDiff) {
                    largestPalindrome = s.substr(i, j);
                }
			}
		}
	}
	return largestPalindrome;
}


int main() {
	string s = "testpilipt";
	
    cout << dynamicPalidrome(s);
}
