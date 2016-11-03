//
//  main.cpp
//  leetcode
//
//  Created by tuyoo on 2016/11/3.
//  Copyright © 2016年 tuyoo. All rights reserved.
//

/*
 Given a string, sort it in decreasing order based on the frequency of characters.
 
 Example 1:
 
 Input:
 "tree"
 
 Output:
 "eert"
 
 Explanation:
 'e' appears twice while 'r' and 't' both appear once.
 So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 Example 2:
 
 Input:
 "cccaaa"
 
 Output:
 "cccaaa"
 
 Explanation:
 Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 Note that "cacaca" is incorrect, as the same characters must be together.
 Example 3:
 
 Input:
 "Aabb"
 
 Output:
 "bbAa"
 
 Explanation:
 "bbaA" is also a valid answer, but "Aabb" is incorrect.
 Note that 'A' and 'a' are treated as two different characters.
 */


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> map;
    for(auto c : s)
        map[c]++;
    sort(s.begin(), s.end(), [&](char c1, char c2){
        if(map[c1] != map[c2])
            return map[c1] > map[c2];
        return c1 > c2;
    });
    return s;
}

//int main(int argc, const char * argv[]) {
//    string teststr = "Mymommaalwayssaid,\"Lifewaslikeaboxofchocolates.Youneverknowwhatyou'regonnaget.";
//    std::cout << teststr << endl;
//    teststr = frequencySort(teststr);
//    std::cout << teststr;
//    return 0;
//}
