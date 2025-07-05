class Solution {
    fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
        val A = if (nums1.size < nums2.size) nums1 else nums2
        val B = if (nums1.size < nums2.size) nums2 else nums1

        val m = A.size
        val n = B.size
        var low = 0
        var high = m

        while (low <= high) {
            val i = (low + high) / 2
            val j = (m + n + 1) / 2 - i

            val maxLeftA = if (i == 0) Int.MIN_VALUE else A[i - 1]
            val minRightA = if (i == m) Int.MAX_VALUE else A[i]

            val maxLeftB = if (j == 0) Int.MIN_VALUE else B[j - 1]
            val minRightB = if (j == n) Int.MAX_VALUE else B[j]

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                return if ((m + n) % 2 == 0) {
                    (maxOf(maxLeftA, maxLeftB) + minOf(minRightA, minRightB)) / 2.0
                } else {
                    maxOf(maxLeftA, maxLeftB).toDouble()
                }
            } else if (maxLeftA > minRightB) {
                high = i - 1
            } else {
                low = i + 1
            }
        }

        throw IllegalArgumentException("Input arrays are not sorted properly.")
    }
}
