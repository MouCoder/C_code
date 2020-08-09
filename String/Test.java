package LeetCode.String;

public class Test {
    public static void main(String[] args) {
        String s = "abcabcbb";
        Solution l = new Solution();
        int a = l.lengthOfLongestSubstring(s);
        System.out.println(a);
    }
}
