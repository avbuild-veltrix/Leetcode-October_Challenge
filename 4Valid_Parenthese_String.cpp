#include<bits/stdc++.h>
using namespace std;

int main(){
    int high = 0;
    int low = 0;
    string s = "()*)*)()";

    cout<<"The string is ";

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            low++;
            high++;
        }else if(s[i] == ')'){
            low--;
            high--;
        }else{
            low--;
            high++;
        }
        low = max(low, 0);
        if(high < 0){
            cout<<"Invalid"<<endl;
        }
    }
    if(low == 0){
        cout<<"valid"<<endl;
    }else{
        cout<<"Invalid"<<endl;
    }
    return 0;
}