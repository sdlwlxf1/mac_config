#include <iostream>

using namespace std;

string addStrings(string num1, string num2) {
    string result;
    int n1 = 0, n2 = 0;
    int len1 = num1.size(), len2 = num2.size();
    int len = len1 > len2 ? len1 : len2;
    for(int i = 0; i < len; i++)
    {
        int n3 = 0, n4 = 0;
        if(len1-1-i >= 0) n3 = num1[len1-1-i] - '0';
        if(len2-1-i >= 0) n4 = num2[len2-1-i] - '0';
        int num = n3 + n4 + n2;
        n1 = num % 10;
        n2 = num / 10;
        result.insert(result.begin(), '0'+n1);
    }
    if(n2 != 0) result.insert(result.begin(), '0'+n2);
    return result;
}

//int main(int argc, const char * argv[]) {
//    string n1 = "111112";
//    string n2 = "1122";
//    string res = addStrings(n1, n2);
//    return 0;
//}
