//
//  34.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/19.
//  Copyright © 2020 gred. All rights reserved.
//

class Solution_34 {
    func swapPairs(_ head: ListNode?) -> ListNode? {
        
        guard let nextNode = head?.next else {
            return head
        }
        
        head?.next = swapPairs(nextNode.next)
        nextNode.next = head
        
        return nextNode
    }
}


func myPrint_34(_ head: ListNode?) -> Void {
    if head != nil {
        print(head?.val)
    } else {
        return
    }
    return myPrint_34(head?.next)
}
