class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // sum of first n odd number is n*n
        // sum of first n even number is n*(n+1)
        // GCD (n*n,n*(n+1)) =  n*(GCD(n,n+1)) = n*1 = n;
        return n;
    }
};