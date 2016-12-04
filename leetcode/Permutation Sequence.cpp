#include <iostream>
#include <vector>

using namespace std;

string getPermutation(string &tmp, int len, int visited[], int &count, int k) {
    if(tmp.size() == len)
    {
        count++;
        if(count == k)
            return tmp;
        else
            return "";
    }
    for(int i = 1; i <= len; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            tmp.insert(tmp.end(), '0'+i);
            string res = getPermutation(tmp, len, visited, count, k);
            if(res != "") return res;
            tmp.erase(tmp.end()-1);
            visited[i] = 0;
        }
    }
    return "";
}

string getPermutation(int n, int k) {
    int visited[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string tmp;
    int count = 0;
    for(int i = 1; i < n+1; i++)
    {
        visited[i] = 1;
        tmp.insert(tmp.end(), '0'+i);
        string res = getPermutation(tmp, n, visited, count, k);
        if(res != "") return res;
        tmp.erase(tmp.end()-1);
        visited[i] = 0;
    }
    return "";
}

//string getPermutation(int n, int k) {
//    int pTable[10] = {1};
//    for(int i = 1; i <= 9; i++){
//        pTable[i] = i * pTable[i - 1];
//    }
//    string result;
//    vector<char> numSet;
//    numSet.push_back('1');
//    numSet.push_back('2');
//    numSet.push_back('3');
//    numSet.push_back('4');
//    numSet.push_back('5');
//    numSet.push_back('6');
//    numSet.push_back('7');
//    numSet.push_back('8');
//    numSet.push_back('9');
//    while(n > 0){
//        int temp = (k - 1) / pTable[n - 1];
//        result += numSet[temp];
//        numSet.erase(numSet.begin() + temp);
//        k = k - temp * pTable[n - 1];
//        n--;
//    }
//    return result;
//}


//int main(int argc, const char * argv[]) {
//    string res = getPermutation(9, 33);
//    return 0;
//}
