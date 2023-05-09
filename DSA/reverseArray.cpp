#include<iostream>
#include<string>
using namespace std;

void reverseArray(string &str, int st, int end){
    if(st>=end) {return ;}
    char temp= str[st];
    str[st]=str[end];
    str[end]=temp;
    return reverseArray(str,st+1,end-1);

}
int main(){
    string str;//="mithra";
    cin >> str;
        cout<<"START "<<endl;
    int strSize= str.size()-1;
    reverseArray(str,0,strSize);
    cout<<str;
    //cout<< "\nTESt";

}
