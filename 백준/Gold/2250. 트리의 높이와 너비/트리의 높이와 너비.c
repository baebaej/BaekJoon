#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int nodeNum;
	int data;
	int level;
	struct TreeNode* left, * right;
} TreeNode;

int k = 1;
int maxlevel = 1;

void inorder(TreeNode* root, int l) {
	if (root) {
		inorder(root->left, l + 1);
		root->data = k++;
		root->level = l;
		if (maxlevel < l) {
			maxlevel = l;
		}
		inorder(root->right, l + 1);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	TreeNode* nodeArr = (TreeNode*)malloc(sizeof(TreeNode) * (n + 1));
	int* parentCheck = (int*)calloc(n + 1, sizeof(int));
	int root = -1;

	for (int i = 0; i < n; i++) {
		int tmp, left, right;
		scanf("%d %d %d", &tmp, &left, &right);
		nodeArr[tmp].nodeNum = tmp;
		nodeArr[tmp].left = (left == -1) ? NULL : &nodeArr[left];
		nodeArr[tmp].right = (right == -1) ? NULL : &nodeArr[right];

		if (left != -1) parentCheck[left] = 1;
		if (right != -1) parentCheck[right] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (parentCheck[i] == 0) {
			root = i;
			break;
		}
	}

	inorder(&nodeArr[root], 1);

	int maxWidth = -1;
	int maxWidthLevel = 1;
	for (int i = 1; i <= maxlevel; i++) {
		int minData = n + 1;
		int maxData = 0;
		for (int j = 1; j <= n; j++) {
			if (nodeArr[j].level == i) {
				if (nodeArr[j].data < minData) minData = nodeArr[j].data;
				if (nodeArr[j].data > maxData) maxData = nodeArr[j].data;
			}
		}
		int width = maxData - minData + 1;
		if (maxWidth < width) {
			maxWidth = width;
			maxWidthLevel = i;
		}
	}

	printf("%d %d\n", maxWidthLevel, maxWidth);

	free(nodeArr);
	free(parentCheck);
}
