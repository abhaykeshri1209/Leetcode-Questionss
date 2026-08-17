/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
       int start = 0;
        int end = mountainArr.length() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }

        int peak = start;

        start = 0;
        end = peak;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) == target) {
                return mid;
            }
            else if (mountainArr.get(mid) < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        // 3. Binary search on decreasing side
        start = peak + 1;
        end = mountainArr.length() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) == target) {
                return mid;
            }
            else if (mountainArr.get(mid) < target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return -1;
    }
};