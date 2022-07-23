# @param {String[]} words
# @param {String} pref
# @return {Integer}
def prefix_count(words, pref)
    
    res=0
    
    for item in words
        if pref==item[0,pref.length]
            res=res+1
        end
    end
    
    return res
end