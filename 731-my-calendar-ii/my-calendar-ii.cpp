class MyCalendarTwo {
public:
    map<int,int> mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime] += 1;
        mp[endTime] -= 1;
        int ts = 0;

        for(auto &[key,val] :mp){
            ts += val;
            if(ts > 2){
                //revert 
                mp[startTime] -= 1;
                mp[endTime] += 1;
                return false;
            } 
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */