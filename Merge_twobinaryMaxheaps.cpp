class Solution{
    public:
    void heapify(vector<int>& heap, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
    
        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;
    
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(heap, n, largest);
    }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        
        for(auto i: a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        int size = ans.size();

        for (int i = size / 2 - 1; i >= 0; i--){
         heapify(ans, size, i);
        }
        
        return ans;
    }
};