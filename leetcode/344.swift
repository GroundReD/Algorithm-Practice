//
//  344.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/12.
//  Copyright © 2020 gred. All rights reserved.
//
class Solution_344 {
    func reverseString(_ s: inout [Character]) {
        s = Array(String(s.reversed()))
    }
}
