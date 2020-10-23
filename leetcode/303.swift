//
//  303.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/19.
//  Copyright © 2020 gred. All rights reserved.
//

class NumArray {

    var sumArray : [Int]
    init(_ nums: [Int]) {
        self.sumArray = [0]
        nums.reduce(0, {(sum: Int, num: Int) -> Int in
            let tmpSum = sum+num
            sumArray.append(tmpSum)
            return tmpSum
        })
    }
    
    func sumRange(_ i: Int, _ j: Int) -> Int {
        return sumArray[j+1] - sumArray[i]
    }
}

