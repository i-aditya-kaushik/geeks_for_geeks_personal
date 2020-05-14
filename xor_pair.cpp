#include <iostream>
#include <unordered_set>
using namespace std;

bool func(int a[],int n,int k);
bool func(int a[],int n,int k){
    unordered_set <int> s;
    for(int i=0;i<n;i++){
        if(s.find(a[i]^k) != s.end()){
            return(1);
        }
        s.insert(a[i]);
    }
    return(0);
}

int main() {
	int n;
	cin>>n;
	bool ans;
	for(int i=0;i<n;i++){
	    int size;
	    cin>>size;
	    int a[size];
	    int k;
	    cin>>k;
	    for(int j=0;j<size;j++){
	        cin>>a[j];
	    }
	    ans = func(a,size,k);
	    if(ans){
	        cout<<"Yes"<<endl;
	    }
	    else{
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}