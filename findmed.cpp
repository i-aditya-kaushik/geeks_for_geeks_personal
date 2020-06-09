Node* findk(Node* node, int k, int& count){
    if(node==NULL){
        return NULL;
    }
    Node* left= findk(node->left,k,count);
    if(left!=NULL) return left;
    count+=1;
    if(count==k) return node;
    return findk(node->right,k,count);
}

int countN(Node* root){
    Node *curr, *pre;
    int count = 0;
    if(!root) return count;
    curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            count+=1;
            curr= curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right!=NULL and pre->right!=curr) pre=pre->right;
            if(pre->right ==NULL){
                pre->right=curr;
                curr= curr->left;
            }
            else{
                pre->right=NULL;
                count+=1;
                curr= curr->right;
            }
        }
    }
    return count;
}

int findmed(Node *root) 
{ 
   if (root == NULL) 
        return 0; 
  
    int count = countN(root); 
    int currC = 0; 
    struct Node *curr = root, *pre, *prev; 
  
    while (curr != NULL) 
    { 
        if (curr->left == NULL) 
        { 
            currC++;
            if (count % 2 != 0 && currC == (count+1)/2) 
                return prev->data; 
            else if (count % 2 == 0 && currC == (count/2)+1) 
                return (prev->data + curr->data)/2; 
            prev = curr; 
            curr = curr->right; 
        } 
        else
        { 
            pre = curr->left; 
            while (pre->right != NULL && pre->right != curr) 
                pre = pre->right; 
            if (pre->right == NULL) 
            { 
                pre->right = curr; 
                curr = curr->left; 
            } 
            else
            { 
                pre->right = NULL; 
                prev = pre; 
                currC++; 
                if (count % 2 != 0 && currC == (count+1)/2 ) 
                    return curr->data; 
  
                else if (count%2==0 && currC == (count/2)+1) 
                    return (prev->data+curr->data)/2; 
                prev = curr; 
                curr = curr->right; 
  
            } 
        } 
    } 
} 

int median(Node *node,int k){
    int count = 0;
    int sum=0;
    Node* kth = findk(node,k,count);
    if(!kth) return 0;
    return(findmed(kth));
}