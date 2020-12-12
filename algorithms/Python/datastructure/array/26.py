#!/usr/bin/python3
# -*- coding: utf-8 -*-
# @Time        : 2020/12/12 8:01 下午
# @Version     : 1.0
# @Author      : BATTERIA
# @Description : 26.remove-duplicates-from-sorted-array
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        last = nums[0]
        result = pre = 1
        for i in range(len(nums)):
            if nums[i] != last:
                last = nums[i]
                nums[pre] = nums[i]
                pre += 1
                result += 1
        return result
