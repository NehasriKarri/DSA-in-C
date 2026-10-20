int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int best = 0;

    while (left < right) {
        // Find the minimum height between the two pointers
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int area = (right - left) * h;
        
        // Update the maximum area found so far
        if (area > best) {
            best = area;
        }

        // Move the pointer pointing to the shorter line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return best;
}
