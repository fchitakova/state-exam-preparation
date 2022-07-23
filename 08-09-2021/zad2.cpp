#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    unsigned int level;
    int value;

    TreeNode(unsigned int level, int value) {
        this->level = level;
        this->value = value;
    }
};


bool hasDuplicates(const std::vector<TreeNode>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i].level == arr[j].level && arr[i].value == arr[j].value)
                return true;
        }
    }
    return false;
}


bool checkForParentNode(size_t parentLevel, size_t searchUntilIndex, std::vector<TreeNode> treeNodes) {
    for(size_t i = 0; i < searchUntilIndex; i++) {
        if(treeNodes.at(i).level == parentLevel) {
            return true;
        }
    }
    return false;
}

/**
 * 1. трябва да проверим за повтарящи се елементи
 * 2. Всеки връх има единствен родител.Искаме за всеки връх, освен корена, да проверим дали родителят му е в редицата преди него.
 *
 * @param treeNodes - редица, описваща дърво.
 * @return указател към корена, ако представянето е валидно дърво
 */
const TreeNode* getRootIfValid(const std::vector<TreeNode>& treeNodes) {
    if(treeNodes.at(0).level != 0 || (treeNodes.size() > 1 && treeNodes.at(1).level != 1) || hasDuplicates(treeNodes)) {
        return nullptr;
    }
    for(size_t i = 1; i< treeNodes.size(); i++){
        if(!checkForParentNode(treeNodes.at(i).level - 1, i, treeNodes))
            return nullptr;
    }
    return &treeNodes.at(0);
}


int main() {

    std::vector<TreeNode> treeNodes;

    //TEST 1 - VALID TREE
//    treeNodes.push_back(TreeNode(0, 5));
//    treeNodes.push_back(TreeNode(1, 4));
//    treeNodes.push_back(TreeNode(1, 5));
//    treeNodes.push_back(TreeNode(2, 3));
//    treeNodes.push_back(TreeNode(1, 6));
//    treeNodes.push_back(TreeNode(2, 2));
//    treeNodes.push_back(TreeNode(3, 3));
//    treeNodes.push_back(TreeNode(2, 5));

    //TEST 2 - VALID TREE
//    treeNodes.push_back(TreeNode(0, 3));

  //TEST 3 - INVALID TREE
//    treeNodes.push_back(TreeNode(1, 4));

    //TEST 4 - INVALID TREE
//    treeNodes.push_back(TreeNode(0, 4));
//    treeNodes.push_back(TreeNode(0, 5));

 //TEST 5 - INVALID TREE

    treeNodes.push_back(TreeNode(0, 1));
    treeNodes.push_back(TreeNode(1, 2));
    treeNodes.push_back(TreeNode(2, 2));
    treeNodes.push_back(TreeNode(3, 1));
    treeNodes.push_back(TreeNode(3, 3));
    treeNodes.push_back(TreeNode(4, 3));


    const TreeNode* root = getRootIfValid(treeNodes);
    if(root != nullptr) {
        std::cout << "Root: ("<< root->level <<", " << root->value << ") .\n";
    } else {
        std:: cout << "Invalid Tree!";
    }

    return 0;
}
