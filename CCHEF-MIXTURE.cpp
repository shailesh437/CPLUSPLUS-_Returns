#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int TC;
	cin>>TC;
	while(TC--){
	    int A,B;
	    cin>>A>>B;
	    if(A==0){
	        cout<<"Liquid"<<endl;
	    }else if(B==0){
	        cout<<"Solid"<<endl;
	    }else{
	        cout<<"Solution"<<endl;
	    }
	}
	return 0;
}
