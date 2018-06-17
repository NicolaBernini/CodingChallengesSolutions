
// Solution to 
// https://www.hackerrank.com/challenges/self-balancing-tree/problem

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */




using namespace std; 

node* plain_insert(node * root,int val)
{
    if(val <= root->val) 
    {
        // Insert Left 
        if(root->left==nullptr)
        {
            root->left = new node(); 
            root->left->val = val; 
            return root->left; 
        }
        else
        {
            plain_insert(root->left, val); 
        }
    }
    else
    {
        // Insert Left 
        if(root->right==nullptr)
        {
            root->right = new node(); 
            root->right->val = val; 
            return root->right; 
        }
        else
        {
            plain_insert(root->right, val); 
        }        
    }
    return nullptr; 
}

void plain_move(node* root, node* target)
{
    if((root==nullptr) || (target==nullptr)) return; 
    plain_insert(root, target->val); 
    plain_move(root, target->left); 
    plain_move(root, target->right); 
    free(target);
}

int balanceFactor(const node* root)
{
    if(root==nullptr) return 0; 
    int temp=0; 
    if(root->left != nullptr) temp = temp + 1 + balanceFactor(root->left); 
    if(root->right != nullptr) temp = temp - 1 + balanceFactor(root->right); 
    return temp; 
}

node* rotate_ccw(node* root)
{
    node* new_root = root->right; 
    node* new_root_l = root; 
    node* new_root_lr = root->right->left; 
    new_root->left = new_root_l; 
    new_root->left->right = new_root_lr; 
    return new_root; 
}

node* rotate_cw(node* root)
{
    node* new_root = root->left; 
    node* new_root_r = root; 
    node* new_root_rl = root->left->right; 
    new_root->right = new_root_r; 
    new_root->right->left = new_root_rl; 
    return new_root; 
}



node* reBalance(node* root, const string& loc)
{
    if(root==nullptr) return root; 
    int bf = balanceFactor(root); 
    //cout << "Node (" << loc << ") --> BF = (" << bf << ") " << endl; 
    if(bf<=-2)
    {
        cout << "Right Rotation needed " << endl; 
        //root->right = rotate_ccw(root->right); 
        root = rotate_ccw(root); 
    }
    if(bf>=2)
    {
        cout << "Left Rotation needed" << endl;
        //root->left = rotate_cw(root->left); 
        root = rotate_cw(root); 
    }
    
    root->left = reBalance(root->left, loc+"L"); 
    root->right = reBalance(root->right, loc+"R"); 
    return root; 
}

void printBST(const node* root, const string& loc)
{
    if(root==nullptr) return; 
    cout << "Loc (" << loc << ") Val=(" << root->val << ") BF=(" << balanceFactor(root) << ") " << endl; 
    printBST(root->left, loc+"L"); 
    printBST(root->right, loc+"R"); 
}


node* insert(node * root,int val)
{
	//cout << "Root Balance = (" << to_string(balanceFactor(root)) << ") " << endl; 
    printBST(root, "");
    plain_insert(root, val);
    cout << endl; 
    printBST(root, "");
    root = reBalance(root, ""); 
    cout << endl; 
    printBST(root, "");
    //cout << "Root Balance = (" << to_string(balanceFactor(root)) << ") " << endl; 
    return root; 
}

