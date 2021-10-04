#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

typedef struct Node
{
    int data, cnt = 0;
    Node* left;
    Node* right;
} node_t;

bool left(int value, const node_t* root) {
    return value < root->data;
}

bool right(int value, const node_t* root) {
    return value > root->data;
}

bool equal(int value, const node_t* root) {
    return value == root->data;
}

node_t* insert(node_t* root, const int value )
{
    if (root == NULL )
    {
        node_t* node = (node_t*)malloc(sizeof(node_t));
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        node->cnt = 1;
        return node;
    }
    if (equal(value, root)) root->cnt += 1;
    else if (left(value, root)) root->left = insert(root->left, value);
    else if (right(value, root)) root->right = insert(root->right, value);
    return root;
}

vector<int> ans;

void inOrder(node_t* root){
    if(root != NULL) {
        inOrder(root->left);
        rep(i,root->cnt) {
            ans.push_back(root->data);
        }
        inOrder(root->right);
    }
}

void preOrder(node_t* root){
    if(root != NULL) {
        rep(i,root->cnt) {
            ans.push_back(root->data);
        }
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n; cin >> n;
    node_t* root = NULL;
    rep(i,n) {
        int x; cin >> x;
        root = insert(root, x);
    }
    inOrder(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ",";
    }
    cout << '\n';
    ans.clear();
    preOrder(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ",";
    }
    cout << '\n';
    return 0;
}