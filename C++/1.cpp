class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> rem;
        int index = 0;
        for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
            unordered_map<int, int>::iterator rem_it = rem.find(target-*it);
            if(rem_it != rem.end()){
                //or use rem_it[target-*it] to get key
                return vector<int>{rem_it->second, index};
            }
            rem[*it] = index++; 
        }
    }
};