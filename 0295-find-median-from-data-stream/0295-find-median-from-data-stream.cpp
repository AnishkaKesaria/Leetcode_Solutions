class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size()==0)
        {
            maxHeap.push(num);
            return;
        }

        double median = findMedian();
        if(maxHeap.size()==minHeap.size())
        {
            if(num>median)
                minHeap.push(num);
            else
                maxHeap.push(num);
        }
        else if(maxHeap.size()>minHeap.size())
        {
            if(num>median)
                minHeap.push(num);
            else
            {
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);
                maxHeap.push(num);
            }
        }
        else
        {
            //minHeap.size()>maxHeap.size()
            if(num<median)
                maxHeap.push(num);
            else
            {
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
                minHeap.push(num);
            }
        }
        return;
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size())
            return (double(maxHeap.top()) + double(minHeap.top()))/2;
        else if(maxHeap.size()>minHeap.size())
            return maxHeap.top();
        else
            return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */