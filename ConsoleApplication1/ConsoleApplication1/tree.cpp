
#include <iostream>
#include <vector>
using namespace std;

struct treeNode {
    treeNode* left;
    treeNode* right;
    int val;

};

vector<int>::iterator find(vector<int> &v,int e) {
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        if (*it==e) {
            return it;
        }
    }
    return it;
}

void Print(vector<int>& v) {
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

treeNode* getTree(vector<int> postorder,vector<int> inorder){

    if (inorder.size()!=0)
    {
        treeNode* root = new treeNode;

        vector<int>::iterator it;
        //看inorder中的每个元素，有在postorder中最大索引的一定是根节点
        vector<int>::iterator maxIndex = postorder.begin();
        for (it = inorder.begin(); it != inorder.end(); it++)
        {
            vector<int>::iterator index = find(postorder,*it);
            if (index > maxIndex)
            {
                maxIndex = index;
            }
        }

        root->val = *maxIndex;
        //Print(inorder);
        cout << root->val << " ";
        //找到这个节点在inorder中的位置
        it = find(inorder, *maxIndex);
        //划分
      
        root->left = getTree(postorder, vector<int>(inorder.begin(), it));
        if (it== inorder.end()-1)
        {
            root->right = getTree(postorder, vector<int>());
        }
        else {
            root->right = getTree(postorder, vector<int>(it + 1, inorder.end()));
        }
 
        return root;
    }
    else {
        return NULL;
    }

}

int main()
{
    int n;
    vector<int> postorder, inorder;
    cin >> n;
    int i;
    for ( i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        postorder.push_back(e);
    }
    for (i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        inorder.push_back(e);
    }

    treeNode* root = getTree(postorder, inorder);
    /*
          1
      2       3
    4    5
    postorder = 4 5 2 3 1
    inorder = 4 2 5 1 3
    preorder = 1 2 4 5 3
    
    */
}
