#include<bits/stdc++.h>
using namespace std;

string removeOutermostParentheses(string s){
    string ans = "";
    int count = 0;
    for(char ch : s){
        if(ch == '('){
            if(count > 0){
                ans += ch;
            }
            count++;
        }
        else{
            count--;
            if(count > 0){
                ans += ch;
            }
        }
    }
    return ans;
}

int main(){
    // string s = "((())()))(()(()))()()()((())()()))";
    string s = "()(())()";

    cout<<"String after removing outermost parenthesis is : ";
    cout<<removeOutermostParentheses(s);
}