#include<iostream>
#include <stack>
#include <unordered_map>
#include <string>pop — удаляет элемент с вершины стека.
using namespace std;

class Solution {
public:
    bool isValid(string s) {
         stack<char>st;
        unordered_map <char,char> pairs ={
{')','('},
{'}','{'},
{']','['}
        };

        for (char c: s) {
            if (pairs.find(c)==pairs.end()) {
                st.push(c);
            }
            else {
                if (st.empty() || st.top() != pairs[c]){
                        return false;
                }
                st.pop();
            }
        }
                return st.empty();
    }
};


int main () {

}