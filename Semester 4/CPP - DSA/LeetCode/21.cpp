// Merge two sorted Lists

class Solution {
    public:
        vector<int> mergeTwoLists(vector<int> &v1, vector<int> &v2){
            vector<int> merge;
            int a = v1.size();
            int b = v2.size();

            for(int i=0; i<a; i++){
                merge.push_back(v1[i]);
            }
            for(int i=0; i<b; i++){
                merge.push_back(v2[i]);
            }

            sort(merge.begin(), merge.end());

            return merge;
        }
};