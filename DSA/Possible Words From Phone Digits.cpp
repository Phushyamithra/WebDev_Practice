#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> ans;

void possibleDigits(string temp, int n,int ind ,int ar[] );

int main(){
    int n;
    cout << "Enter how many numbers you want to enter : ";
    cin>> n;
    int ar[n];
    for(int i=0;i<n;i++){
        cout << "Enter the number you want to enter : ";
        cin>> ar[i];
    }
    possibleDigits("",n,0,ar);

    cout<< "Possible words are :";
    //2cout << ans.size();
    for(int i=0; i<ans.size();i++){
        cout<< ans[i] <<endl;
    }
}

void possibleDigits(string temp, int n,int ind ,int ar[] ){
    //cout<< "Called";
    // Base condn
    if(ind==n){
        //cout << temp;
        ans.push_back(temp);
        return;
    }
    // Loop Recursion
    for(int i=0;i<keys[ar[ind]].size();i++){
        possibleDigits(temp+keys[ar[ind]][i],n,ind+1,ar);
    }
    return;
}
