class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime] += 1;
        mp[endTime] -= 1;

        int ts = 0;

        for(auto &[key,val] : mp){
            ts += val;
            if(ts > 1){
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */