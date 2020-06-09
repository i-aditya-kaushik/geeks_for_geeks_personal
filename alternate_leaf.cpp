#include <iostream>
using namespace std;

struct Node{ 
    int data; 
    Node *left, *right; 
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; 

void lf(Node* root, int& flag, int& sum){
    if (!root) 
        return; 
    if (!root->left && !root->right){ 
        if(flag==1){flag=0;}
        else{
            sum += root->data;
            flag=1;
        }
    }
    lf(root->left, flag,sum); 
    lf(root->right, flag,sum); 
}

Node *newNode(Node* newn , int num){ 
    if(newn==NULL){
        newn= new Node(num);
    }
    else{
        if(num<newn->data){
            newn->left = newNode(newn->left,num);
        }
        else{
            newn->right = newNode(newn->right,num);
        }
    }
    return newn;
} 

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    Node* root = NULL;
	    int size,data;
	    cin>>size;
	    for(int j=0;j<size;j++){
	        cin>>data;
	        root= newNode(root,data);
	    }
	    int flag=0;
	    int sum =0;
	    lf(root,flag,sum);
	    cout<<sum<<endl;
	}
	return 0;
}