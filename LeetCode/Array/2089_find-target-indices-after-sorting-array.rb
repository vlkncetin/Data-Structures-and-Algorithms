# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def target_indices(nums, target)
    
    nums=nums.sort
    
    i=0
    arr=[]
    for item in nums
       if target==item
           arr.push(i)
       end
        i=i+1
    end
    
    return arr
end