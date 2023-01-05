// 1227. Airplane Seat Assignment Probability

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1){return (double)1;}
        return (double)1/2;
    }
};