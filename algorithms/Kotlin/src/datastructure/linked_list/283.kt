package datastructure.linked_list

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2020/12/12
 * @description: 26.remove-duplicates-from-sorted-array
 */
fun removeDuplicates(nums: IntArray): Int {
    if (nums.isEmpty()) return 0
    var result = 1
    var left = 1
    var last = nums[0]
    for (i in nums.indices) {
        if (nums[i] != last) {
            last = nums[i]
            nums[left++] = nums[i]
            result++
        }
    }
    return result
}

fun main() {

}