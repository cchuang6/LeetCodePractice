class TwoSum {
public:
    unordered_map<int, int> map;
    void add(int number) {
       map[number]++;
    }
       
    
    bool find(int value) {
        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            int data = it->first;
            if(((value - data == data) && (it->second > 1) )||(value-data != data && map.find(value-data) != map.end()))
                return true;
        }
        return false;
    }
};