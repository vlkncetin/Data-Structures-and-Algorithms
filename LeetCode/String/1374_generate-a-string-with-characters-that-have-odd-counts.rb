# @param {Integer} n
# @return {String}
def generate_the_string(n)
    
    s=""
    if n%2==1
      s="a"*n
    else
      s="a"*(n-1)+"b"  
    end
    
    return s
end