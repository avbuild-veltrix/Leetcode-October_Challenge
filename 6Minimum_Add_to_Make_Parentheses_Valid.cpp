#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s){
    stack<char> st;
    int count = 0;
    for(char ch : s){
        if(ch == '('){
            st.push(ch);
            count++;
        }
        if(!st.empty() && st.top() == '(' && ch == ')'){
            st.pop();
            count--;
        }else if(ch == ')' && (st.empty() || st.top() != '(')){
            st.push(ch);
            count++;
        }
    }
    return count;
}


// int minAddToMakeValid(string s){
//     int open = 0;
//     int ans = 0;

//     for(char ch : s){
//         if(ch == '('){
//             open++;
//         }else{
//             if(open > 0){
//                 open--;
//             }else{
//                 ans++;
//             }
//         }
//     }
//     return ans+open;
// }

int main(){
    string s = "())(())))(((";

    cout<<"Minimum parentheses add to make string valid is : ";
    cout<<minAddToMakeValid(s)<<endl;

}