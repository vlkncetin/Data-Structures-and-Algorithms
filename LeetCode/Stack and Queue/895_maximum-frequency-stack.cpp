class FreqStack {
public:
    int maxFreq;
    unordered_map<int, int> freqMap;
    unordered_map<int, stack<int>> freqStackMap; // to store the numbers with same freq in a stack
    
    FreqStack() {
        
        maxFreq=0;
    }
    
    void push(int val) {
        ++freqMap[val];
        
        if(maxFreq<freqMap[val])
            maxFreq = freqMap[val];
        
        freqStackMap[freqMap[val]].push(val);
    }
    
    int pop() {
        int res = freqStackMap[maxFreq].top();
        
        freqStackMap[maxFreq].pop();
        --freqMap[res];
        
        if(freqStackMap[maxFreq].empty())
        {
            freqStackMap.erase(maxFreq);
            --maxFreq;
        }
        
        return res;
    }
};