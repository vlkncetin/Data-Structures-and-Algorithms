# @param {String} word1
# @param {String} word2
# @return {String}
def merge_alternately(word1, word2)
    
    res=""
    
    for i in 0...word1.length
       res=res+word1[i]
        if i<word2.length
            res=res+word2[i]
        end
    end
    
    if word1.length<word2.length
       res=res+word2[word1.length,word2.length-word1.length] 
    end
    
    return res
end