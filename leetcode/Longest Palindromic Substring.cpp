#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    if(s.length() < 2)
        return s;
    int maxLen = 1;
    int maxTag = 0;
    if(s[0] == s[1])
    {
        maxLen = 2;
        maxTag = 1;
    }
    char last = s[1];
    char ago = s[0];
    for(int i = 2; i < s.length(); i++)
    {
        if(last == s[i])
        {
            int len = 2;
            for(int j = 1, k = -2; i+j < s.length() && i-k >=0 && s[i+j] == s[i+k]; j++, k--)
                len+=2;
            if(len > maxLen) {
                maxLen = len;
                maxTag = i;
            }
            
        }
        if(ago == s[i]) {
            int len = 3;
            for(int j = 1, k = -3; i+j < s.length() && i-k >=0 && s[i+j] == s[i+k]; j++, k--)
                len+=2;
            if(len > maxLen) {
                maxLen = len;
                maxTag = i-1;
            }
        }
        ago = last;
        last = s[i];
    }
    if(maxLen == 0)
        return "";
    return s.substr(maxTag-maxLen/2, maxLen);
}

//int main(int argc, const char * argv[]) {
//    string ss = "ccd";
//    string res = longestPalindrome(ss);
//    return 0;
//}
