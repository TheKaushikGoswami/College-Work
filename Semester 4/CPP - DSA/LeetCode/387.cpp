class Solution {
    public:
        int firstUniqChar(string s) {
            int index = -1;
            bool flag = false;
    
            for(char c: s){
                for(int i = 1; i<s.length(); i++){
                    if(s[i] == c){
                        flag = true;
                        break;
                    }
                }
                index = s.find(c);
            }
    
            return index;
        }
};