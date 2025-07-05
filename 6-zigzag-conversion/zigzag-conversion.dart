class Solution {
  String convert(String s, int numRows) {
    if (numRows == 1 || s.length <= numRows) return s;

    List<StringBuffer> rows = List.generate(numRows, (_) => StringBuffer());
    int currentRow = 0;
    bool goingDown = false;

    for (int i = 0; i < s.length; i++) {
      rows[currentRow].write(s[i]);
      if (currentRow == 0 || currentRow == numRows - 1) goingDown = !goingDown;
      currentRow += goingDown ? 1 : -1;
    }

    return rows.map((row) => row.toString()).join('');
  }
}
