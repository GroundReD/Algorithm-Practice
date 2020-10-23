//
//  1277.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/25.
//  Copyright © 2020 gred. All rights reserved.
//

class Solution_1277 {
    func countSquares(_ matrix: [[Int]]) -> Int {
        let rowLen: Int = matrix.count
        let colLen: Int = matrix[0].count
        var resultMatrix = matrix
        var result: Int = 0
        
        for i in 0..<rowLen {
            for j in 0..<colLen {
                if matrix[i][j] != 0 {
                    resultMatrix[i][j] = checkMaxLen(resultMatrix, i, j)
                    result += resultMatrix[i][j]
                }
            }
        }
//
//        let result = resultMatrix.flatMap{$0}.reduce(0, {(res:Int, val:Int) -> Int in
//            return res+val
//        })
//
        return result
    }
    
    func checkMaxLen(_ matrix: [[Int]], _ row: Int, _ col: Int) -> Int {
        var maxLengthRow: Int = 1
        var maxLengthCol: Int = 1
        var offset: Int
        
        if row>0 && col>0 {
            offset = matrix[row-1][col-1]
        } else {
            return 1
        }
        
        if offset == 0 {
            return 1
        }
        
        for i in 1...offset {
            if matrix[row][col-i] == 0 || matrix[row-i][col] == 0 {
                break
            }
            
            if matrix[row-i][col] != 0 {
                maxLengthRow += 1
            }
            
            if matrix[row][col-i] != 0 {
                maxLengthCol += 1
            }
        }
        return min(maxLengthCol, maxLengthRow)
    }
}
