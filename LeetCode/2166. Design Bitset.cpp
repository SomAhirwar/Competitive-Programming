class Bitset {
    string s;
    int ones;
    int fliped;
public:
    Bitset()
    {
        s = "";
        ones = 0;
        fliped = 0;
    }
    
    Bitset(int size) {
        s = "";
        ones = 0;
        fliped = 0;
        for(int i=0; i<size; i++)
            s.push_back('0');
    }
    
    void fix(int idx) {
        
        int temp = fliped;
        
        char bit = (temp==1)?'0':'1';
        
        if(bit == s[idx])
            return;
        ones++;
        
        s[idx] = bit;
    }
    
    void unfix(int idx) {
        char bit = fliped==1?'1':'0';
        
        if(bit == s[idx])
            return;
        
        ones--;
        s[idx] = bit;
        
    }
    
    void flip() {
        fliped = 1-fliped;
        ones = s.size() - ones;
    }
    
    bool all() {
        return s.size() == ones;
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        if(!fliped)
            return s;
        
        string t = "";
        for(char c: s)
        {
            if(c=='0')
                t.push_back('1');
            else
                t.push_back('0');
        }
        
        return t;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
