class Solution {
public:
    string defangIPaddr(string address) {
        string dIP;
        for(auto c: address)
            (c=='.') ? dIP+="[.]" : dIP += c;
        
        return dIP;
    }
};