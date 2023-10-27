class MedianFinder {
public:
    priority_queue<int> leftLargest;
    priority_queue<int, vector<int>, greater<>> rightSmallest;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (leftLargest.size() && num > leftLargest.top()) rightSmallest.push(num);
        else leftLargest.push(num);
        
        //rebalance
        if ((int)leftLargest.size() - (int)rightSmallest.size() > 1){
            int top = leftLargest.top();
            leftLargest.pop();
            rightSmallest.push(top);
        }
        
        if ((int)rightSmallest.size() - (int)leftLargest.size() > 1){
            int top = rightSmallest.top();
            rightSmallest.pop();
            leftLargest.push(top);
        }

    }
    
    double findMedian() {
        int totSz = leftLargest.size() + rightSmallest.size();

        if (totSz % 2){
            if (leftLargest.size() > rightSmallest.size())
                return leftLargest.top();
            else
                return rightSmallest.top();
        }
        return ((double)leftLargest.top() + rightSmallest.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */