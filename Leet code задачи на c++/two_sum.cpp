#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solucation{
    public:
vector<int> twoSum(vector<int>& nums, int target){
unordered_map<int, int>NumMap;
for (int i=0; i< nums.size(); i++) {
int comp=target-nums[i];

if (NumMap.find(comp) != NumMap.end()) {

    return{NumMap[comp], i};
}
NumMap[nums[i]]=i;

}
return{};
}

};

int main () {

    Solucation solu;
    vector<int> nums = {9, 7, 2, 15};
    int target = 9;

 vector<int> result = solu.twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}