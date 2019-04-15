#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;
    
public:
    Time()
    {
        hours = 00;
        minutes = 00;
        seconds = 00;
    }
    
    int get_seconds()
    {
        return seconds;
    }
    
    int get_minutes()
    {
        return minutes;
    }
    
    int get_hours()
    {
        return hours;
    }
    
    void set_time_by_seconds(int s)
    {
        if (s == 0) {
            hours = 0;
            minutes = 0;
            seconds = 0;
        } else {
            seconds = s;
            minutes = s / 60;
            hours = minutes / 60;
            
            seconds = s % 60;
            minutes %= 60;
        }
    }
    
    void increase_time_by_seconds(int s)
    {
        int TH = hours * 60 * 60;
        int TM = minutes * 60;
        int TS = seconds;
        
        int total_seconds = TH + TM + TS + s;
        
        set_time_by_seconds(total_seconds);
    }
    
    void decrease_time_by_seconds(int s)
    {
        int TH = hours * 60 * 60;
        int TM = minutes * 60;
        int TS = seconds;
        
        int total_seconds = (TH + TM + TS) - s;
        
        if (total_seconds < 0) {
            set_time_by_seconds(0);
        } else {
            set_time_by_seconds(total_seconds);
        }
    }
    
    string get_time()
    {
        string str = to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
        return str;
    }
};
