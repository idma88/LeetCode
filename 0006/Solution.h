class Solution {
public:
  string convert(string s, int numRows) {
    string out;

    int ind, line;
    const int sLen = s.length();
    const int step = std::max(1, 2 * numRows - 2);

    out.reserve(sLen);

    for (line = 0; line < numRows; ++line) {
      ind = line;

      while (ind < sLen) {
        out.push_back(s.at(ind));

        if (line != 0 && line != numRows - 1) {
          const int subInd = ind + (step - 2 * line);
          if (subInd < sLen)
            out.push_back(s.at(subInd));
        }

        ind += step;
      }
    }

    return out;
  }
};