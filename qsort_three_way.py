"""Comparison of regular quicksort with 3-way quicksort.

In this module, I compare the performance of regular random-partition quicksort with
3-way random-partition quicksort when the array to be sorted has many duplicates.
"""
import random
import sys
from perf_utils import timer


@timer
def quicksort_3way(nums):
    def partition(nums, left, right):
        pivot_idx = random.randint(left, right)
        pivot_elem = nums[pivot_idx]

        lptr, cptr, rptr = left, left, right

        while cptr <= rptr:
            if nums[cptr] < pivot_elem:
                nums[cptr], nums[lptr] = nums[lptr], nums[cptr]
                lptr += 1
                cptr += 1
            elif nums[cptr] == pivot_elem:
                cptr += 1
            else:
                nums[cptr], nums[rptr] = nums[rptr], nums[cptr]
                rptr -= 1
        return lptr, rptr

    def qsort(nums, left, right):
        if left >= right:
            return
        lptr, rptr = partition(nums, left, right)
        qsort(nums, left, lptr - 1)
        qsort(nums, rptr + 1, right)

    qsort(nums, 0, len(nums) - 1)


@timer
def quicksort(nums):
    def partition(nums, left, right):
        pivot_idx = random.randint(left, right)
        pivot_elem = nums[pivot_idx]
        nums[left], nums[pivot_idx] = nums[pivot_idx], nums[left]
        lptr = left + 1

        for rptr in range(left + 1, right + 1):
            if nums[rptr] < pivot_elem:
                nums[lptr], nums[rptr] = nums[rptr], nums[lptr]
                lptr += 1

        nums[lptr - 1], nums[left] = nums[left], nums[lptr - 1]

        return lptr - 1

    def qsort(nums, left, right):
        if left >= right:
            return

        pivot_idx = partition(nums, left, right)
        qsort(nums, left, pivot_idx - 1)
        qsort(nums, pivot_idx + 1, right)

    qsort(nums, 0, len(nums) - 1)


def in_place_perf(arr, alg):
    t = arr.copy()
    alg(t)


if __name__ == "__main__":
    a = []
    for i in range(100):
        a.extend([i] * 1000)
    a.reverse()

    sys.setrecursionlimit(5000)
    in_place_perf(a, quicksort)
    in_place_perf(a, quicksort_3way)
