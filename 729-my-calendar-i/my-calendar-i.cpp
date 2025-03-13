class MyCalendar {
public:
    map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int start = it->first;
            int end = it->second;
            if (max(start, startTime) < min(end, endTime)) {
                return false;
            }
        }
        mp[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */