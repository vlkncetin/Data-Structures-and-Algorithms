# @param {Integer[][]} mat
# @return {Integer}
def diagonal_sum(mat)
    
    i=0
    j=mat.length-1
    sum=0
    for item in mat
        sum=sum+item[i]
        sum=sum+item[j]
        i=i+1
        j=j-1
    end
    
    if mat.length%2==1
       sum=sum-mat[mat.length/2][mat.length/2] 
    end
    
    return sum
end