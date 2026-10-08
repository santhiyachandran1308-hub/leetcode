void nextPermutation(int* nums, int numsSize) {
    int i, j, temp;
    i = numsSize - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        j = numsSize - 1;

        while (nums[j] <= nums[i]) {
            j--;
        }
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    j = numsSize - 1;
    i = i + 1;

    while (i < j) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;

        i++;
        j--;
    }
}
