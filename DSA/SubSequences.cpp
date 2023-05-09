#include<iostream>

using namespace std;

void printSubSequences(string str, string tempAns,int index,int strSize){
    if(index==strSize){
        cout<< tempAns <<endl;
        return;
    }
    // take condition 
    printSubSequences(str,tempAns+str[index],index+1,strSize);
    //not take
    printSubSequences(str,tempAns,index+1,strSize);

    return;
}

int main(){
    string str;
    cout<< "Enter your String" ;
    cin >> str;
    int strSize=str.size();
    printSubSequences(str,"",0,strSize);
}