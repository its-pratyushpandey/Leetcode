class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $n = strlen($s);
        $set = [];
        $maxLength = 0;
        $left = 0;

        for ($right = 0; $right < $n; $right++) {
            $char = $s[$right];
            
            while (isset($set[$char])) {
                unset($set[$s[$left]]);
                $left++;
            }

            $set[$char] = true;
            $maxLength = max($maxLength, $right - $left + 1);
        }

        return $maxLength;
    }
}
