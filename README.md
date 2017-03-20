# concordance
A custom word counting application.

## HOW TO USE:

.\concordance .\this_is_a_text_file.txt

## Algorithmic Complexity

Assuming the std library qsort functions like the algorithm by the same name, we can assume a typical case of O(log(n)). I use a hash structure to store the elements, so the hash building/reading is O(n). This leads to a total time of Theta T(2n+log(n))), with upper bound of O(2n+n^2). The space complexity is n, due to the use of a hash.
