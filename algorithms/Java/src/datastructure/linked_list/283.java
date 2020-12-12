package datastructure.linked_list;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/12
 * @description: 26.remove-duplicates-from-sorted-array
 */
class Solution {
    public int removeDuplicates(int[] nums) {
        int size = nums.length;
        if (size == 0) return 0;
        int last = nums[0], left = 1, result = 1;
        for (int i = 1; i < size; i++) {
            int temp = nums[i];
            if (temp != last) {
                last = temp;
                nums[left++] = temp;
                result++;
            }
        }
        return result;
    }

    public static void main(String[] args) {

    }
}
