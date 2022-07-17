# @param {String} s
# @return {Integer}
def count_asterisks(s)
    res=0
    
    isFirstFound=false;
    for i in 0...s.length
        if s[i]=="|" && !isFirstFound
            isFirstFound=true
        elsif s[i]=="|" && isFirstFound
            isFirstFound=false
        elsif !isFirstFound && s[i]=="*"
            res=res+1
        end
    end
    return res;
end