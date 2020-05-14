#include <iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

void func(int a[],int n,int k);
int possible(int a[],int n,int m);

int possible(int a[],int n,int m){
    int res = 0;
    for(int i=0;i<n;i++){
        res+= upper_bound(a+i,a+n,a[i]+m)-a-i-1;
    }
    return res;
}

void func(int a[],int n,int k){
    
    sort(a,a+n);
    int lower = a[1]-a[0];
    for(int i=1;i<n-1;i++){
        lower = min(lower,a[i+1]-a[i]);
    }
    int max = a[n-1]-a[0];
    while(lower<max){
        int middle = (lower+max)/2;
        if(possible(a,n,middle)<k){
            lower = middle+1;
        }
        else{
            max = middle;
        }
    }
    cout<<lower<<endl;
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
	    func(a,size,k);
	}
	return 0;
}