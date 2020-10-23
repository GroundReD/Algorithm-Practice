//
//  791.swift
//  leetcode-practice
//
//  Created by 박지홍 on 2020/01/12.
//  Copyright © 2020 gred. All rights reserved.
//

class Solution_791 {
    func customSortString(_ S: String, _ T: String) -> String {
        let alpbtDict: [String.Element:Int] = ["a":0,"b":1,"c":2,"d":3,"e":4,"f":5,"g":6,"h":7,"i":8,"j":9,"k":10,"l":11,"m":12,"n":13,"o":14,"p":15,"q":16,"r":17,"s":18,"t":19,"u":20,"v":21,"w":22,"x":23,"y":24,"z":25]
        var sortIndex = Array("abcdefghijklmnopqrstuvwxyz");
        var countIndex: [Int] = [Int](repeating: 0, count: 26)
        let arrS = Array(S)
        let arrT = Array(T)
        
        for i in 0..<S.count {
            sortIndex[ alpbtDict[arrS[i]]! ] = "."
        }
        
        let newArr = arrS + sortIndex.filter({(value: String.Element) -> Bool in return (value != ".")})
        
        
        // count number of character in string T
        for str in arrT {
            countIndex[alpbtDict[str]!] += 1
        }
        
        var result: String = ""

        for i in 0..<newArr.count {
            
            let count:Int = countIndex[alpbtDict[newArr[i]]!]
            for _ in 0..<count {
                result.append(newArr[i])
            }
        }

        return result
    }
}


