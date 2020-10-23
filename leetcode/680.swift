//
//  680.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/10.
//  Copyright © 2020 gred. All rights reserved.
//

class Solution_680 {
    func validPalindrome(_ s:String) -> Bool {
        let cstr = Array(s)
        let start = 0
        let end = s.count-1
        return sol(cstr, start, end, 0)
    }
    
    /**
     Check that Given String is Palindrome
     - parameter str: Given String
     - parameter start : First Index of Given String
     - parameter end : Last Index of Given String
     - parameter check : check skipped count
      
    - returns: Boolean of Givne String is palindrome
    */

    func sol(_ str:[Character], _ start:Int, _ end:Int, _ check: Int) -> Bool {
        if str.isEmpty {
            return true
        }
        
        if start >= end {
            return true
        }
        
        if check > 1 {
            return false
        }

        if str[start] == str[end] {
            return sol(str, start+1, end-1, check)
        } else if check < 1{
            return sol(str, start+1, end, check+1) || sol(str, start, end-1, check+1)
        } else {
            return false
        }
    }
    
    func solFailed(_ str:String, _ check: Int) -> Bool {
        if str.isEmpty {
            return true
        }
        
        let start = str.startIndex
        let end = str.endIndex
        
        if start >= end {
            return true
        }
        
        if check > 1 {
            return false
        }
    
        if str[start] == str[str.index(before:end)] {
            return solFailed(String(str[str.index(after: start)..<str.index(before:end)]), check)
        } else if check < 1{
            return solFailed(String(str[str.index(after: start)..<end]), check+1) || solFailed(String(str[start..<str.index(before:end)]), check+1)
        } else {
            return false
        }
    }
}
