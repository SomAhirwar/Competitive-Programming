class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0, beams = 0;
        int n = bank.size();
        for(int i=0; i<n; i++)
        {
            int l = 0;
            for(char c: bank[i])
                l += c=='1';
            beams += (last * l);
            last = l?l:last;
        }
        
        return beams;
    }
};
