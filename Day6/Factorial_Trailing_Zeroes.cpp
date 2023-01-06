// 172. Factorial Trailing Zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int div = 5, zeros = 0;
        while(n/div != 0){
            zeros += n/div;
            div *= 5;
        }
        return zeros;
    }
};