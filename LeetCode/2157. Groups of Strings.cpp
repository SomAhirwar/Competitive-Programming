//O(25*25*N)
class disjointSet
{
    vector<int> arr;
    int n;

public:
    disjointSet(int n1)
    {
        n = n1;
        arr = vector<int>(n, -1);
    }

    int find(int a)
    {
        if (arr[a] < 0)
            return a;

        return arr[a] = find(arr[a]);
    }

    bool inSameSet(int a, int b)
    {
        int s1 = find(a), s2 = find(b);
        if (s1 == s2)
            return true;

        return false;
    }

    void uninon(int a, int b)
    {
        int s1 = find(a), s2 = find(b);
        if(s1 == s2)
            return;
        if (arr[s1] > arr[s2]) //size of set s1 is small
        {
            arr[s2] += arr[s1];
            arr[s1] = s2;
        }
        else
        {
            arr[s1] += arr[s2];
            arr[s2] = s1;
        }
    }

    void printSet()
    {
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
    
    int totalSets()
    {
        int cnt = 0;
        for(int i: arr)
            if(i<0)
                cnt++;
        
        return cnt;
    }
    
    int maxSize()
    {
        int mx = 0;
        for(int i: arr)
            mx = min(i, mx);
        
        return mx*-1;
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size(), m=words[0].size();
        
        vector<int> sets(n);
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            int mask = 0;
            for(int j=0; j<words[i].size(); j++)
            {
                mask = mask | (1<<(words[i][j] - 'a'));
            }
            sets[i] = mask;
            mp[mask] = i;
            // cout<<mask<<" "<<mp[mask]<<endl;
        }
        
        disjointSet ds(n);
        
        for(int i=0; i<n; i++)
        {
            ds.uninon(i, mp[sets[i]]); //connecting all of the words with same set of alphabates
            // cout<<i<< " "<<map[i]<<endl;
            
            for(int j=0; j<26; j++) //adding and deleting a letter in the word
            {
                int newMask = sets[i] ^ (1<<j);
                if(mp.find(newMask) != mp.end())
                {
                    // cout<<i<<" "<<j<<" "<<newMask<<endl;
                    ds.uninon(i, mp[newMask]);
                }
            }
            
            for(int j=0; j<26; j++) //replacing letter
            {
                if(sets[i] & (1<<j))
                {
                    for(int k=0; k<26; k++)
                    {
                        if(j==k || (sets[i] & (1<<k))>0)
                            continue;
                        if(mp.find(sets[i] ^ (1<<j) ^ (1<<k)) != mp.end())
                        {
                            ds.uninon(i, mp[sets[i] ^ (1<<j) ^ (1<<k)]);  //deleing j'th letter and adding k'th letter
                            // cout<<i<<" "<<j<<" "<<k<<" "<<(sets[i] ^ (1<<j) ^ (1<<k))<<endl;
                        }
                    }
                }
            }
        }
        
        int totalSet = ds.totalSets();
        int mxSize = ds.maxSize();
        
        return {totalSet, mxSize};
   }
};

//--------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

O(25 * N) Solution


class disjointSet
{
    vector<int> arr;
    int n;

public:
    disjointSet(int n1)
    {
        n = n1;
        arr = vector<int>(n, -1);
    }

    int find(int a)
    {
        if (arr[a] < 0)
            return a;

        return arr[a] = find(arr[a]);
    }

    bool inSameSet(int a, int b)
    {
        int s1 = find(a), s2 = find(b);
        if (s1 == s2)
            return true;

        return false;
    }

    void uninon(int a, int b)
    {
        int s1 = find(a), s2 = find(b);
        if(s1 == s2)
            return;
        if (arr[s1] > arr[s2]) //size of set s1 is small
        {
            arr[s2] += arr[s1];
            arr[s1] = s2;
        }
        else
        {
            arr[s1] += arr[s2];
            arr[s2] = s1;
        }
    }

    void printSet()
    {
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
    
    int totalSets()
    {
        int cnt = 0;
        for(int i: arr)
            if(i<0)
                cnt++;
        
        return cnt;
    }
    
    int maxSize()
    {
        int mx = 0;
        for(int i: arr)
            mx = min(i, mx);
        
        return mx*-1;
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size(), m=words[0].size();
        
        vector<int> sets(n);
        unordered_map<int, int> mp, deletes;
        
        for(int i=0; i<n; i++)
        {
            int mask = 0;
            for(int j=0; j<words[i].size(); j++)
            {
                mask = mask | (1<<(words[i][j] - 'a'));
            }
            sets[i] = mask;
            mp[mask] = i;
            // cout<<mask<<" "<<mp[mask]<<endl;
        }
        
        disjointSet ds(n);
        
        for(int i=0; i<n; i++)
        {
            ds.uninon(i, mp[sets[i]]); //connecting all of the words with same set of alphabates

            //adding a bit to obtain anotehr string is same as deleting a bit from another string to get curr string
            //if string s2 is achived from s1 by replcaement, s1 and s2 an be equaled by deleting single letter from both string s1 and s2
            for(int j=0; j<26; j++) //adding and deleting a letter in the word
            {
                if(0 == (sets[i] & (1<<j)))
                    continue;
                
                int newMask = sets[i] ^ (1<<j);
                
                if(mp.find(newMask) != mp.end())
                    ds.uninon(i, mp[newMask]);
                
                if(deletes.find(newMask) != deletes.end())
                    ds.uninon(i, deletes[newMask]);
                else
                    deletes[newMask] = i; 
            }
        }
        
        int totalSet = ds.totalSets();
        int mxSize = ds.maxSize();
        
        return {totalSet, mxSize};
   }
};
