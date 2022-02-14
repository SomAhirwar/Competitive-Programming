class Solution {
public:
    int countOperations(int num1, int num2) {
        if(!num1 || !num2)
            return 0;
        int cnt = 0;
        do {
            if(num1<num2)
                swap(num1, num2);
            num1 -= num2;
            cnt++;
        } while(num1 && num2);
        
        return cnt;
    }
};
