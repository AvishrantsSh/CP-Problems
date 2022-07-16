#include <iostream>

using namespace std;

string reverse_string(string s){
    if(s.size() == 0) return "";
    return reverse_string(s.substr(1)) + s[0];
}

string replace_pi(string s){
    if(s.size() == 0) return "";
    if(s[0] == 'p' && s[1] == 'i') return "3.14" + replace_pi(s.substr(2));
    return s[0] + replace_pi(s.substr(1));
}

void towerOfHanoi(int n, char src, char dest, char helper){
    if(n == 0) return;
    towerOfHanoi(n-1, src, helper, dest);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    towerOfHanoi(n-1, helper, dest, src);
}

string remove_seq_duplicates(string s){
    if(s.length() == 0) return "";
    string tmp = remove_seq_duplicates(s.substr(1));
    if(s[0] == tmp[0]) return tmp;
    return s[0] + tmp;
}

string moveXtoEnd(string s){
    if(s.length() == 0) return "";
    string tmp = moveXtoEnd(s.substr(1));
    if(s[0] == 'x') return tmp + 'x';
    return s[0] + tmp;
}

void getSubstring(string s, string ans){
    if(s.length() == 0) {
        cout << ans << endl;
        return;
    };
    getSubstring(s.substr(1), ans);
    getSubstring(s.substr(1), ans + s[0]);
}

int main(){
    cout << reverse_string("aman") << endl;
    cout << replace_pi("amaipipiipipi") << endl;
    towerOfHanoi(3, 'A', 'B', 'C');
    cout << remove_seq_duplicates("aaabbabaabbababaa") << endl;
    cout << moveXtoEnd("axxxcxxscsgusx") << endl;
    getSubstring("abc", "");
}