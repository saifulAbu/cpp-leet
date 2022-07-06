class ParkingSystem {
    const static int BIG = 1, MID = 2, SMALL = 3;
    int b = 0, m = 0, s = 0;
public:
    ParkingSystem(int big, int medium, int small) {
        this->b = big;
        this->m = medium;
        this->s = small;
    }
    
    bool addCar(int carType) {
        switch (carType)
        {
        case BIG:
            if(b == 0) {
                return false;
            }
            b--;
            break;
        case MID:
            if(m == 0) {
                return false;
            }
            m--;
            break;
        default:
            if(s == 0) {
                return false;
            }
            s--;
            break;
        }
        return true;
    }
};

