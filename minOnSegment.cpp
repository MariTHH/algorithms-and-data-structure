#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct SegmentTree {
    int start;
    int end;
    int minVal;
    SegmentTree *left;
    SegmentTree *right;

    SegmentTree(int start, int end) : start(start), end(end), minVal(0), left(nullptr), right(nullptr) {}
};

SegmentTree* build(vector<int>& arr, int start, int end) {
    if (start == end) {
        SegmentTree* tree = new SegmentTree(start, end);
        tree->minVal = arr[start];
        return tree;
    }

    int mid = start + (end - start) / 2;
    SegmentTree* leftChild = build(arr, start, mid);
    SegmentTree* rightChild = build(arr, mid + 1, end);

    SegmentTree* tree = new SegmentTree(start, end);
    tree->left = leftChild;
    tree->right = rightChild;
    tree->minVal = min(leftChild->minVal, rightChild->minVal);

    return tree;
}

int queryMinimum(SegmentTree* root, int start, int end) {
    if (root->start == start && root->end == end) {
        return root->minVal;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (end <= mid) {
        return queryMinimum(root->left, start, end);
    } else if (start > mid) {
        return queryMinimum(root->right, start, end);
    } else {
        return min(queryMinimum(root->left, start, mid), queryMinimum(root->right, mid + 1, end));
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> seq(n);
    for (int& x : seq) {
        cin >> x;
    }
    SegmentTree* root = build(seq, 0, n - 1);
    cout << queryMinimum(root, 0, k - 1) << " ";
    for (int i = k; i < n; i++) {
        cout << queryMinimum(root, i - k + 1, i) << " ";
    }

    return 0;
}
