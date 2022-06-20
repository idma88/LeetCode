class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;

        int maxLen = 1;

        string::iterator first = s.begin(), last = next(s.begin());

        for (size_t i = 1; i < s.length(); ++i) {
            auto prev = find(first, last, s.at(i));

            if (prev != last) {
                // found
                if (prev == first) {
                    first = next(first);
                } else {
                    maxLen = max(maxLen, (int)distance(first, last));
                    first  = next(prev);
                }
            }
            last = next(last);
        }

        return max(maxLen, (int)distance(first, last));
    }
};