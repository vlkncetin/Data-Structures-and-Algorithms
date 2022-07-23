# @param {Integer[]} nums
# @return {Integer}
def max_product_difference(nums)
    
    nums=nums.sort
    w=nums[nums.length-1]
    x=nums[nums.length-2]
    y=nums[0]
    z=nums[1]
    
    return (w*x)-(y*z)
end