#include <iostream>

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

void reverseInorder(Node* root, int& cnt, int& result) {
    if (!root || cnt <= 0) return;
    reverseInorder(root->right, cnt, result);
    if (cnt <= 0) return;
    cnt--;
    if (cnt == 0) {
        result = root->val;
        return;
    }
    reverseInorder(root->left, cnt, result);
}

int main() {
    Node* root = nullptr;
    for (int i = 0; i < 7; ++i) {
        int val;
        if (!(std::cin >> val)) break;
        root = insert(root, val);
    }
    int cnt;
    if (!(std::cin >> cnt)) return 0;
    int result = -1;
    int tempCnt = cnt;
    reverseInorder(root, tempCnt, result);
    std::cout << result << std::endl;
    return 0;
}
