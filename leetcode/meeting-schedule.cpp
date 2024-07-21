// Meeting Schedule

// Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), determine if a person could add all meetings to their schedule without any conflicts.

// Example 1:

// Input: intervals = [(0,30),(5,10),(15,20)]

// Output: false
// Explanation:

// (0,30) and (5,10) will conflict
// (0,30) and (15,20) will conflict
// Example 2:

// Input: intervals = [(5,8),(9,15)]

// Output: true
// Note:

// (0,8),(8,10) is not considered a conflict at 8
// Constraints:

// 0 <= intervals.length <= 500
// 0 <= intervals[i].start < intervals[i].end <= 1,000,000

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        // MODIFIED: need to sort the intervals by their start times before traversing
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b)
             { return a.start < b.start; });

        int late_end = -1;
        for (Interval curr_int : intervals)
        {
            if (late_end > curr_int.start)
            {
                return false;
            }
            else if (curr_int.end > late_end)
            {
                late_end = curr_int.end;
            }
        }
        return true;
    }
};