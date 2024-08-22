class Solution {
public:
     int maxArea(vector<int>& height) {
        int left = 0;              // Start with the left pointer at the beginning
        int right = height.size() - 1;  // Start with the right pointer at the end
        int maxArea = 0;           // Initialize max area to 0

        while (left < right) {
            // Calculate the area between the lines at the left and right pointers
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;  // Return the maximum area found
    }
};




