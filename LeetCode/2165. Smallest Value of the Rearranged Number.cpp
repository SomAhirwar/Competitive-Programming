class Solution {
public:
    long long smallestNumber(long long num) {
        if( num == 0)
            return num;
        if(num<0)
            return negative(num);
        
        return positive(num);
    }
    
    long long positive(long long n)
    {
        string s = to_string(n);
        sort(begin(s), end(s));
        
        int j=0;
        while(s[j]-'0' == 0)
            j++;
        long long no = s[j] - '0';
        for(int i=0; i<s.size(); i++)
        {
            if(i==j)
                continue;
            no = no*10 + (s[i]- '0');
        }
        
        return no;
    }
    
    long long negative(long long n)
    {
        string s = to_string(n);
        sort(s.begin()+1, s.end(), [](char a, char b) {
            return a>b;
        });
        
        long long no = 0;
        for(int i=1; i<s.size(); i++)
            no = no*10 + (s[i] - '0');
        
        return no*(-1);
            
    }
};
