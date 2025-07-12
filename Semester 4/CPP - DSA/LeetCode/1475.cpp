class Solution {
    public:
        vector<int> finalPrices(vector<int>& prices) {
    
            vector<int> answer;
            for(int i = 0; i < prices.size(); i++){
                bool found = false;
                for(int j = i+1; j < prices.size(); j++){
                    if(prices[j] <= prices[i]){
                        answer.push_back(prices[i] - prices[j]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    answer.push_back(prices[i]);
                }
            }
    
            return answer;
            
        }
};