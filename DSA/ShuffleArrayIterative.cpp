#include <bits/stdc++.h>
using namespace std;

void shuffleArray(){
	int left=0,right;
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
	if(n%2==0){
		right=n/2;
	}
	else{
		right=(n/2)+1;
	}
    right++;
    int aVal=arr[1];
    int temp;
    int i=2;
    while(left< (n/2)){
        temp=aVal;
        arr[i]=temp;
        arr[i+1]=arr[right];
        aVal=arr[i];
        left++;
        right++;
        i=i+2;
    }
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
}
int main() {
	shuffleArray();
	return 0;
}
// } Drive