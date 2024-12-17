//https://leetcode.com/problems/ransom-note/

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] rans = new int[26];
        int[] mag = new int[26];
        for(int i=0; i<ransomNote.length(); ++i)
            rans[ransomNote.charAt(i)-'a']++;
        for(int i=0; i<magazine.length(); ++i)
            mag[magazine.charAt(i)-'a']++;
        
        for(int i=0; i<26; ++i)
            if(rans[i] != 0 && rans[i] > mag[i])
                return false;
        return true;
    }
}
