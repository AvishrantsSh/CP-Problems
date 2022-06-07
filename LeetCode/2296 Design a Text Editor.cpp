class TextEditor {
public:
    string ltext = "", rtext="";
    TextEditor() {}
    
    void addText(string text) {
        ltext += text;
    }
    
    int deleteText(int k) {
        k = min(k, (int) ltext.size());
        ltext.resize(ltext.size() - k);
        return k;
    }
    
    string cursorLeft(int k) {
        for(;k > 0 && !ltext.empty(); ltext.pop_back(), k--)
            rtext.push_back(ltext.back());
            
        return ltext.size() >= 10 ? ltext.substr(ltext.size()-10, 10): ltext;
    }
    
    string cursorRight(int k) {
        for(;k > 0 && !rtext.empty(); rtext.pop_back(), k--)
            ltext.push_back(rtext.back());
        
        return ltext.size() >= 10 ? ltext.substr(ltext.size()-10, 10): ltext;
    }
};
