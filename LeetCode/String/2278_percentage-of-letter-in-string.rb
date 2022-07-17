# @param {String} s
# @param {Character} letter
# @return {Integer}
def percentage_letter(s, letter)
    
    numLetter=0
    
    for i in 0...s.length
       if s[i]==letter
           numLetter=numLetter+1
       end
    end
        
    return numLetter*100/s.length
end