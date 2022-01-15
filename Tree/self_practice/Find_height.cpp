// Given a generic tree, find and return the height of given tree.


/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

int maxi = 0;
int curr = 0;

int helper(TreeNode<int>* root){
        // Write your code here
    if(root->children.size() != 0){
        curr++;
    }
    
    if(root->children.size() == 0){
        curr++;
        return curr;
    }
    
    for(int i = 0 ; i < root->children.size() ; i++){
        curr = helper(root->children[i]);
        if(curr > maxi){
            maxi = curr;
        }
        curr--;
    }
    
    return curr;
}

int getHeight(TreeNode<int>* root) {
	int garbage = helper(root);
    if(maxi == 0){
        return garbage;
    }
    return maxi;
}
