#include<bits/stdc++.h>
using namespace std;

void generateParentheses(string s, int open, int close, int n, vector<string> &ans){
    if(s.length() == 2*n){
        ans.push_back(s);
        return;
    }

    if(open < n){
        generateParentheses(s + '(', open + 1, close, n, ans);
    }

    if(close < open){
        generateParentheses(s + ')', open, close + 1, n, ans);
    }
}

int main(){
    string s = {};
    vector<string> ans = {};
    int n = 3;
    generateParentheses(s,0,0,n,ans);

    cout << "Possible combinations are:\n";

    for(string x : ans) {
        cout << x << endl;
    }
    return 0;
}