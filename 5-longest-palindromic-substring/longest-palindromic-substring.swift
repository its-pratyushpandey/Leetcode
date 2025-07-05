class Solution {
    func longestPalindrome(_ s: String) -> String {
        if s.count < 2 { return s }
        let chars = Array(s)
        var start = 0
        var maxLength = 1
        
        func expandAroundCenter(_ left: Int, _ right: Int) {
            var l = left
            var r = right
            while l >= 0 && r < chars.count && chars[l] == chars[r] {
                if r - l + 1 > maxLength {
                    start = l
                    maxLength = r - l + 1
                }
                l -= 1
                r += 1
            }
        }
        
        for i in 0..<chars.count {
            expandAroundCenter(i, i)
            expandAroundCenter(i, i + 1)
        }
        
        let startIdx = s.index(s.startIndex, offsetBy: start)
        let endIdx = s.index(startIdx, offsetBy: maxLength)
        return String(s[startIdx..<endIdx])
    }
}
