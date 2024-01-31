/*
Given an unsorted array of integers  nums, return  the length of the longest consecutive elements sequence.

Basic Test Case:

Input: [100, 4, 200, 1, 3, 2]
Expected Output: 4

Empty Array:
Input: []
Expected Output: 0

Array with One Element:
Input: [5]
Expected Output: 1

*/

import java.util.Arrays;

public class LongestConsecutiveSequence {
    public static void main(String[] args) {
        int[] nums = {100, 4, 200, 1, 3, 2};

        int result = longestConsecutive(nums);
        System.out.println("Length of the Longest Consecutive Sequence: " + result);
    }

    public static int longestConsecutive(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        // Sort the array
        Arrays.sort(nums);

        int longestStreak = 1;
        int currentStreak = 1;

        // Iterate through the sorted array
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                // If the current element is consecutive to the previous one, increment the current streak
                if (nums[i] == nums[i - 1] + 1) {
                    currentStreak++;
                } else {
                    // If not consecutive, reset the current streak
                    currentStreak = 1;
                }

                // Update the longest streak
                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}

