class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        m_big=big;
        m_medium=medium;
        m_small=small;
    }
    
    bool addCar(int carType) {
        if(carType==1)
        {
            if(m_big>0)
            {
                m_big--;
                return true;
            }
            else
                return false;
        }
        else if(carType==2)
        {
            if(m_medium>0)
            {
                m_medium--;
                return true;
            }
            else
                return false;
        }
        else if(carType==3)
        {
            if(m_small>0)
            {
                m_small--;
                return true;
            }
            else
                return false;
        }
        
        return false;
    }
    
private:
    int m_big;
    int m_medium;
    int m_small;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */