// CODESTUDIO -- Check If The String Is A Palindrome

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char toLowerCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    } else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isAlphaNumeric(char ch) {
    return isalnum(ch);
}

bool checkPalindrome(string s) {
    int st = 0;
    int e = s.size() - 1;

    while (st <= e) {
        if (!isAlphaNumeric(s[st])) {
            st++;
            continue;
        }
        if (!isAlphaNumeric(s[e])) {
            e--;
            continue;
        }
        if (toLowerCase(s[st]) != toLowerCase(s[e])) {
            return false;
        }
        st++;
        e--;
    }

    return true;
}

int main() {
    string s = "N2 i&nJA?a& jnI2n";

    bool ans = checkPalindrome(s);

    cout << "The String is palindrome: " << boolalpha << ans << endl;

    return 0;
}
