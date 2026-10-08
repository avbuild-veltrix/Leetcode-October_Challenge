#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

void DFS(string s, int index, int count, int left, int right, string current, bool prevRemoved){
    if(index == s.length()){
        if(left == 0 && right == 0 && count == 0){
            ans.push_back(current);
        }
        return;
    }

    char ch = s[index];

    if(ch == '('){
        if(index == 0 || s[index] != s[index - 1] || prevRemoved){
            if(left > 0){
                DFS(s, index+1, count, left-1, right, current, true);
            }
        }
        DFS(s, index + 1, count + 1, left, right, current + '(', false);
    }
    else if(ch == ')'){
        if(right > 0){
            if(index == 0 || s[index] != s[index - 1] || prevRemoved){
                DFS(s, index + 1, count, left, right - 1, current, true);
            }
        }
        if(count > 0){
            DFS(s, index + 1, count - 1, left, right, current + ')', false);
        }
    }
    else{
        DFS(s, index + 1, count, left, right, current + ch, false);
    }
}

vector<string> removeInvalidParentheses(string s){
    ans.clear();

    int left = 0;
    int right = 0;
    int count = 0;

    bool prevRemoved = false;

    //Find minimum number of removals.

    for(char ch : s){
        if(ch == '('){
            count++;
        }
        else if(ch == ')'){
            count--;
            if(count < 0){
                count = 0;
                right++;
            }
        }
    }
    left = count;
    DFS(s,0,0,left,right,"", false);

    return ans;
}

int main(){
    string s = "()())()";

    removeInvalidParentheses(s);
    cout<<"A list of unique strings that are valid with the minimum number of removals : ";
    cout<<"[";
    for(int i = 0; i < ans.size(); i++){
        cout<<"'"<<ans[i]<<"',"<<" ";
    }
    cout<<"]"<<endl;
}