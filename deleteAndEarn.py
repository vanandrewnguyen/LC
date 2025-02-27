class Solution:
    def findMaxEarn(self, nums: List[int], mem: List[int], i: int) -> int:
        if (i < 0):
            return 1
        if (mem[i] >= 0):
            return mem[i]
        mem[i] = max(self.findMaxEarn(nums, mem, i-2) + nums[i], self.findMaxEarn(nums, mem, i-1))
        print(mem[i])
        return mem[i]
        
    def deleteAndEarn(self, nums: List[int]) -> int:
        # this is just house robber but the values are the numbers * occ..., [2,3,4] -> [2,3,4], [2,2,3] -> [4,3]
        nums.sort()
        uniqList = list(set(nums))

        # what if numbers aren't consecutive? e.g. 1 2 5 5 7 -> 1 2 5 7 -> should be like, 1 2 0 5 0 7
        # cleaned list will have spaces between non consec nums.
        cleanedList = [uniqList[0]]
        for i in range(1, len(uniqList)):
            diff = uniqList[i] - uniqList[i - 1]
            for _ in range(diff - 1):
                cleanedList.append(0)
            cleanedList.append(uniqList[i])

        for i, elem in enumerate(cleanedList):
            cleanedList[i] = elem * nums.count(elem)
        
        # now we have house robber....
        mem: List[int] = [-1] * (len(cleanedList)+1)

        print(cleanedList, mem)

        return self.findMaxEarn(cleanedList, mem, len(cleanedList)-1)-1
    
    

