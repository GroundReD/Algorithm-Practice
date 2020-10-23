//
//  1277.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/23.
//  Copyright © 2020 gred. All rights reserved.
//




class Solution_206 {
    func reverseList(_ head: ListNode?) -> ListNode? {
        return reverseListInternal(nil, head)
    }
    
    func reverseListInternal (_ prev: ListNode?, _ curr: ListNode?) -> ListNode? {
        if curr == nil { return prev }
        
        let next = curr?.next
        curr?.next = prev
        
        return reverseListInternal(curr, next)
    }
}

func myPrint(_ head: ListNode?) -> Void {
    if head != nil {
        print(head?.val)
    } else {
        return
    }
    return myPrint(head?.next)
}

let node1 = ListNode(1)
let node2 = ListNode(2)
let node3 = ListNode(3)
let node4 = ListNode(4)
let node5 = ListNode(5)

//node1.next = node2
//node2.next = node3
//node3.next = node4
//node4.next = node5

//var sol = Solution_13()
//sol.reverseList(node1)

//myPrint(node5)
