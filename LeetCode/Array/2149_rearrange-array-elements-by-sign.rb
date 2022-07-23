# @param {Integer[]} nums
# @return {Integer[]}
def rearrange_array(nums)
    
    pos=[]
    neg=[]
    res=[]
    
    for item in nums
        if item<0
            neg.push(item)
        else
            pos.push(item)
        end
    end
    
    for i in 0...nums.length/2
       res.push(pos[i])
        res.push(neg[i])
    end
    
    return res
end