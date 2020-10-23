//
//  File.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/25.
//  Copyright © 2020 gred. All rights reserved.
//

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution_617 {
    func mergeTrees(_ t1: TreeNode?, _ t2: TreeNode?) -> TreeNode? {
        guard let mt1 = t1 else {
            return t2
        }
        
        guard let mt2 = t2 else {
            return t1
        }
        
        mt1.val +=  mt2.val
        
        //left branch
        mt1.left = mergeTrees(mt1.left, mt2.left)
        
        //right branch
        mt1.right = mergeTrees(mt1.right, mt2.right)
        
        return mt1
    }
}
