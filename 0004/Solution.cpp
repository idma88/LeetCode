class Solution {
  public:
    using Iter = vector<int>::iterator;

    Iter minOf(Iter& it1, Iter& it2, Iter end1, Iter end2) {
        if (it1 != end1) {
            if (it2 != end2)
                return (*it1 < *it2 ? it1++ : it2++);
            else
                return it1++;
        } else {
            if (it2 != end2)
                return it2++;
            else
                return end1; //! WTF
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, count = 1, stopAt = (nums1.size() + nums2.size() + 1) / 2;

        if (nums1.size() + nums2.size() == 0)
            return 0;

        Iter it1 = nums1.begin();
        Iter it2 = nums2.begin();
        Iter it3 = minOf(it1, it2, nums1.end(), nums2.end()), it4 = it3;

        while (count < stopAt) {
            it3 = minOf(it1, it2, nums1.end(), nums2.end());
            ++count;
        }

        if ((nums1.size() + nums2.size()) % 2) {
            return *it3;
        } else {
            it4 = minOf(it1, it2, nums1.end(), nums2.end());
            return ((double)*it3 + *it4) / 2;
        }
    }
};