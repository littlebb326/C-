#include <iostream>
using namespace std;
int n;
// Node node_arr[27];
// struct Node
// {
//     char data;
//     Node *left;
//     Node *right;
//     Node(char _data, Node *_left, Node *_right)
//     {
//         data = _data;
//         left = _left;
//         right = _right;
//     }
// };
char tree[26][2] = {
    '.',
};
void preorder(char root)
{
    char left = tree[root - 'A'][0];
    char right = tree[root - 'A'][1];
    cout << root;
    if (left != '.')
        preorder(left);
    if (right != '.')
        preorder(right);
}
void inorder(char root)
{
    char left = tree[root - 'A'][0];
    char right = tree[root - 'A'][1];
    if (left != '.')
        inorder(left);
    cout << root;
    if (right != '.')
        inorder(right);
}
void postorder(char root)
{
    char left = tree[root - 'A'][0];
    char right = tree[root - 'A'][1];
    if (left != '.')
        postorder(left);
    if (right != '.')
        postorder(right);
    cout << root;
}
void init_tree()
{
    for (int i = 0; i < 26; i++)
    {
        tree[i][0] = '.';
        tree[i][1] = '.';
    }
}
int main()
{
    cin >> n;
    init_tree();
    for (int i = 1; i <= n; i++)
    {
        char data, left, right;
        cin >> data >> left >> right;
        tree[data - 'A'][0] = left;
        tree[data - 'A'][1] = right;
    }
    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
    cout << endl;
    return 0;
}