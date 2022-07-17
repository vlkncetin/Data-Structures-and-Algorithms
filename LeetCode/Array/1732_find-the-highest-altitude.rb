# @param {Integer[]} gain
# @return {Integer}
def largest_altitude(gain)
    
    largest=0
    current=0
    for i in 0...gain.length
        current=current+gain[i]
        if largest<current
            largest=current
        end
    end
    
    return largest
end