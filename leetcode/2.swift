//
//  2.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/27.
//  Copyright © 2020 gred. All rights reserved.
//

class Solution_2 {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var l1 = l1
        var l2 = l2
        var result: ListNode? = ListNode(0)
        
        let head: ListNode? = result
        var carry: Int = 0
        
        while l1 != nil || l2 != nil || carry > 0 {
            let val1 = l1?.val ?? 0
            let val2 = l2?.val ?? 0
            let tmpSum = val1 + val2 + carry
            
            let newVal = tmpSum % 10
            carry = tmpSum/10
            
            result?.next = ListNode(newVal)
            result = result?.next
            
            l1 = l1?.next
            l2 = l2?.next
        }
        
        return head?.next
    }
}
