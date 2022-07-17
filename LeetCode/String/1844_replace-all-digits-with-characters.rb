# @param {String} s
# @return {String}
def replace_digits(s)
    
    for i in 0...s.length
        if i%2==1
            temp=s[i-1]
            for j in 0...s[i].to_i
                temp=temp.next
            end
            s[i]=temp
        end
    end
    
    return s
end