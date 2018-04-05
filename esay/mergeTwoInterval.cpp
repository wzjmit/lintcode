/* Example
Given list1 = [(1,2),(3,4)] and list2 = [(2,3),(5,6)], return [(1,4),(5,6)].
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
*/
class Solution {
public:
    /**
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
        // write your code here
        
        int l = list1.size();
        int l2 = list2.size();
        vector<Interval> v;
        int i = 0;
        int j = 0;
        int r;
        while (i < l && j < l2)
        {
            cout << list1[i].start << " " << list2[j].start << endl;
            while (list1[i].start <= list2[j].start && i < l)
                v.push_back(list1[i++]);

            while (list2[j].start < list1[i].start && j < l2)
                v.push_back(list2[j++]);
        }

        while (j < l2) v.push_back(list2[j++]);
        while (i < l) v.push_back(list1[i++]);
        return removeReplica(v);
    }
    static vector<Interval> removeReplica(vector<Interval> intervals) {
        vector<Interval> v;
        v.push_back(intervals[0]);
        int j = 0;
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i].start > v[j].end) {
                v.push_back(intervals[i]);
                j ++;
            } else if (intervals[i].end >= v[j].end ) {
                v[j].end = intervals[i].end;
            }
        }
        return v;
    }
};
