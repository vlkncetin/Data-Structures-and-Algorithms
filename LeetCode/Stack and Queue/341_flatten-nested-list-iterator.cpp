/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        for(int i=nestedList.size()-1; i>=0; i--)
        {
            stackNodes.push(nestedList[i]);
        }
    }

int next() {
    
    int temp = stackNodes.top().getInteger();
    
    stackNodes.pop();
    
    return temp;
}

bool hasNext() {
    while(!stackNodes.empty())
    {
        NestedInteger topNode = stackNodes.top();
        if(topNode.isInteger())
            return true;
        
        stackNodes.pop();
        
        vector<NestedInteger> subList = topNode.getList();
        
        for(int i=subList.size()-1; i>=0; i--)
        {
            stackNodes.push(subList[i]);
        }
    }
    
    return false;
}
    
private:
    stack<NestedInteger> stackNodes;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */