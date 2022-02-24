class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(!num)
            return true;
        return num%10;
    }
};
