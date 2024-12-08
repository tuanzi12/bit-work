#include "BinaryTree.h"
//#include "Queue.h"

int main()
{
	// 手动构建
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);
	BTNode* node8 = BuyNode(8);
	BTNode* node9 = BuyNode(9);

	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node4->_left = node5;
	node4->_right = node6;

	node2->_right = node7;
	node3->_left = node8;
	node6->_right = node9;

	BinaryTreePrevOrder(node1);
	printf("\n");

	BinaryTreeInOrder(node1);
	printf("\n");

	BinaryTreePostOrder(node1);
	printf("\n");

	printf("TreeSize：%d\n", BinaryTreeSize(node1));

	//size = 0;
	printf("TreeSize：%d\n", BinaryTreeSize(node1));

	printf("TreeComplete：%d\n", BinaryTreeComplete(node1));

	/*printf("TreeHeight:%d\n", BinaryTreeHeight(node1));*/

	BinaryTreeDestory(node1);
	node1 = NULL;

	return 0;
}
