//
//  3.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/18.
//  Copyright © 2020 gred. All rights reserved.
//

class Solution_3 {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        
        if (s.count <= 1) {
            return s.count
        }
        
        var startIndex: String.Index = s.startIndex
        var endIndex: String.Index = s.index(after:startIndex)
        var count: Int = 1
        var maxCount: Int = 0
        var dict: [String.Element : Bool] = [s[startIndex]:true]
        
        while endIndex < s.endIndex {
            
            if dict[s[endIndex], default :false]  {
                count -= 1
                dict[s[startIndex]] = false
                startIndex = s.index(after:startIndex)
            } else {
                count += 1
                dict[s[endIndex]] = true
                endIndex = s.index(after:endIndex)
                
            }
            
            if (maxCount <= count) {
                maxCount = count
            }
            
        }
        
        return maxCount
    }
}

