#include <iostream>
#include <vector>

using namespace std;

int hIndex(vector<int> &citations) {
    int beg = 0, end = citations.size()-1;
    while(beg <= end)
    {
        int mid = (beg + end) >> 1;
        int rank = citations.size() - mid;
        if(citations[mid] < rank)
        {
            beg = mid+1;
            continue;
        }
        if(citations[mid-1] >= rank-1)
        {
            end = mid-1;
            continue;
        }
        return citations.size()-mid;
    }
    return citations.size()-beg;
}

//int main() {
//    vector<int> ci = {1,4,7,9};
//    int res = hIndex(ci);
//    return 0;
//}
