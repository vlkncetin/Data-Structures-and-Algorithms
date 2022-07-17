# @param {String} coordinates
# @return {Boolean}
def square_is_white(coordinates)
    
    if coordinates[1].to_i%2==0
       if coordinates[0]=="a" || coordinates[0]=="c" || coordinates[0]=="e" || coordinates[0]=="g"  
           return true
       else
           return false
       end
    elsif coordinates[1].to_i%2==1
       if coordinates[0]=="a" || coordinates[0]=="c" || coordinates[0]=="e" || coordinates[0]=="g"  
           return false
       else
           return true
       end
    end
           
    return true
end