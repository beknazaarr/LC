#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solucation {
    public:
int romad(string s) {
unordered_map<char,int> romad= {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
};
 int total=0;
 int prev=0;

 for (int i=s.length()-1;i>=0;i--) {
    int current=romad[s[i]];
    if (current>prev)
     total -= current;
     else 
     total += current;
    prev = current;
 }
return total;

}

};



int main () {
    Solucation t1;
    string s;
    cin>>s;
    int result=t1.romad(s);
    cout<<result<<endl;
    return 0;
};
