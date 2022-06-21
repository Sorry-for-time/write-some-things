#include "../core/extends-tree.h"

typedef int TreeData;                   /* 定义节点数据域数据类型 */
typedef struct TreeNode *TreeNodeUsage; /* 定义节点的指针类型 */
typedef struct TreeNode {               /* 节点结构 */
    TreeData dataDomain;                /* 数据域 */
    TreeNodeUsage left;                 /* 左孩子指针 */
    TreeNodeUsage right;                /* 右孩子指针 */
} TreeNode;

/**
 * @details 定义树结构描述
 */
typedef struct BinaryTree {
    /**
     * @brief 根节点描述
     */
    TreeNodeUsage root;
    /**
     * @details 用于比较两个节点之间大小的函数, 设有节点A和B情况下
     * @details  1.如果A>B, 那么返回1; 2.如果A<B, 返回-1; 3.如果A==B, 返回0
     * @param A 插入的新节点
     * @param B 参与比较的旧节点
     * @return { 1 | 0 | -1}
     */
    int (*comparator)(TreeNode *A, TreeNode *B);
} BinaryTree, *BTreeLink;

/**
 * @details 二叉树初始化工厂函数, 返回生成的二叉树结构实例描述指针
 * @param comparator 节点值比较器函数, 用于比较节点的大小关系
 * @return { BtreeLink | NULL }
 */
BTreeLink BinaryTreeFactory(int (*comparator)(TreeNode *newNode, TreeNode *oldNode)) {
    BTreeLink back = (BTreeLink) malloc(sizeof(BinaryTree));
    if (back) {
        back->root = NULL;
        back->comparator = comparator;
        return back;
    }
    return NULL;
}

/**
 * @details 判断当前二叉树是否为空树
 * @param treeLink 二叉树实例指针
 * @return { bool }
 */
bool isBinaryTreeEmpty(BTreeLink treeLink) {
    return treeLink->root == NULL;
}

/**
 * @details 节点值域比较器
 * @details 设有A,B两节点, 如果A<B, 返回-1, 如果A>B, 返回1, 否则为相等或无法比较的情况, 返回0
 * @param newNode 新插入的节点
 * @param compareNode 参与比较的已存在节点
 * @return { -1 | 0 | 1}
 */
int comparator(TreeNodeUsage newNode, TreeNodeUsage compareNode) {
    if (newNode->dataDomain <= compareNode->dataDomain) { /* 插入左子树的情况 */
        return -1;
    } else if (newNode->dataDomain > compareNode->dataDomain) { /* 插入右子树的情况 */
        return 1;
    } else {
        return 0;
    }
}

/**
 * @details 往二叉树实例当中插入新的节点
 * @param bTreeLink 二叉树实例
 * @param data 插入的数据
 * @return { bool }
 */
bool insertNodeToTree(BTreeLink bTreeLink, TreeData data) {
    TreeNodeUsage newNode = (TreeNodeUsage) malloc(sizeof(TreeNode));
    if (newNode) {
        // 新建节点的数据初始化
        newNode->dataDomain = data;
        newNode->left = NULL;
        newNode->right = NULL;

        if (isBinaryTreeEmpty(bTreeLink)) {
            bTreeLink->root = newNode;
        } else {                                       /* 树不为空的情况 */
            TreeNodeUsage locRecord = bTreeLink->root; /* 记录位置 */
            while (true) {
                if (bTreeLink->comparator(newNode, locRecord) == -1) { /* 往左子树节点插入的情况 */
                    if (locRecord->left == NULL) {
                        locRecord->left = newNode;
                        return true;
                    }
                    locRecord = locRecord->left;                             /* 更新比较节点的位置 */
                } else if (bTreeLink->comparator(newNode, locRecord) == 1) { /* 往右子树节点插入的情况 */
                    if (locRecord->right == NULL) {
                        locRecord->right = newNode;
                        return true;
                    }
                    locRecord = locRecord->right; /* 更新比较节的点的位置 */
                } else {
                    return false; /* 如果存在节点数据与相同的情况直接结束判断 */
                }
            }
        }
    }
    return false; /* 新节点生成失败直接返回false */
}

/**
 * @details 中序遍历
 * @param treeNodeUsage 树的根节点引用
 */
void inTraversal(TreeNodeUsage treeNodeUsage) {
    if (treeNodeUsage) {
        inTraversal(treeNodeUsage->left);
        printf("%d ", treeNodeUsage->dataDomain);
        inTraversal(treeNodeUsage->right);
    }
}

/**
 * @details 先序遍历
 * @param treeNodeUsage 树的根节点引用
 */
void preTraversal(TreeNodeUsage treeNodeUsage) {
    if (treeNodeUsage) {
        printf("%d ", treeNodeUsage->dataDomain);
        preTraversal(treeNodeUsage->left);
        preTraversal(treeNodeUsage->right);
    }
}

/**
 * @details 后序遍历
 * @param treeNodeUsage 树的根节点引用
 */
void postTraversal(TreeNodeUsage treeNodeUsage) {
    if (treeNodeUsage) {
        postTraversal(treeNodeUsage->left);
        preTraversal(treeNodeUsage->right);
        printf("%d ", treeNodeUsage->dataDomain);
    }
}

bool deleteNodeByInTraversalRuler(BTreeLink treeLink, int loc, TreeData *payload) {
    if (isBinaryTreeEmpty(treeLink)) {
        return false;
    }
    int count = 0;
    return false;
}
