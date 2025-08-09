#include <iostream>
using namespace std;

class Solution {
    public:
    bool isPalindrome(int x) {
     if (x==0) return true;
     if (x<0 || x%10==0) return false;
      int resreset_num=0;
       while(x>resreset_num) {
        int pop=x%10;
        x/=10;
        resreset_num=resreset_num+10+pop;
    
    }

    if (x==resreset_num || x== (resreset_num/=10)) return true;
    return false;
    }

};

int main () {
    Solution solu;
    solu.isPalindrome(0);
    return 0;
}