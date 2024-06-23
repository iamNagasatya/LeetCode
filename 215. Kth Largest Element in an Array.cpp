class Solution {
public:
    int partition(vector<int>& A, int l, int h) {
        int pivot = A[l];
        int i = l - 1;
        int j = h + 1;
        while (true) {
            do {
                i++;
            } while (A[i] < pivot);
            do {
                j--;
            } while (A[j] > pivot);
            if (i >= j) {
                return j;
            }
            swap(A[i], A[j]);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left < right) {
            int i = partition(nums, left, right);
            if (i < n - k) {
                left = i + 1;
            } else {
                right = i;
            }
        }
        return nums[n - k];
    }

};