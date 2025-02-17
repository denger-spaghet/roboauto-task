#include "INode.h"

class TreeNode : public INode {
    public:
        explicit TreeNode(int val) : nodeValue(val) {}
    
        [[nodiscard]] int value() const override {
            return nodeValue;
        }
    
        [[nodiscard]] const std::vector<std::unique_ptr<INode>>& children() const override {
            return childNodes;
        }
    
        void addChild(std::unique_ptr<TreeNode> child) {
            childNodes.push_back(std::move(child));
        }
    
    private:
        int nodeValue;
        std::vector<std::unique_ptr<INode>> childNodes;
    };
    
