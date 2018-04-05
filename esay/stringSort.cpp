/*55 string sort [花了很长时间，sort string 并且comp是依据其他的数据结构]
Example
Given str = “bloomberg”, return “bbooeglmr”.

Explanation:
'b' appears the most frequently, and the dictionary sequence is the smallest, so it is ranked first, followed by 'o'.
Given str = “lintcode”, return “cdeilnot”.

Explanation:
All characters appear the same number of times, so directly in accordance with the dictionary order.
参考others
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        });
*/
int counts[256] = {0};
class Solution {
public:
    /**
     * @param str: the string that needs to be sorted
     * @return: sorted string
     */
    string stringSort(string &str) {
        // Write your code here
        
        for (char c : str)
            ++counts[c];
            
        sort(str.begin(), str.end(), myComp);
        return str;
    }
    static bool myComp(char a, char b) {
        return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
    }
};
