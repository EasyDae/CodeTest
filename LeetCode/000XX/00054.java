//https://leetcode.com/problems/spiral-matrix/

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        
        if(matrix.length == 0)
            return list;
        
        int rbegin = 0, rend = matrix.length-1;
        int cbegin = 0, cend = matrix[0].length-1;
        
        while(rbegin <= rend && cbegin <= cend){
            for(int i=cbegin; i<=cend; ++i)
                list.add(matrix[rbegin][i]);
            rbegin++;
            
            for(int i=rbegin; i<=rend; ++i)
                list.add(matrix[i][cend]);
            cend--;
            
            if(rbegin <= rend)
                for(int i=cend; i>=cbegin; --i)
                    list.add(matrix[rend][i]);
            rend--;
            
            if(cbegin <= cend)
                for(int i=rend; i>=rbegin; --i)
                    list.add(matrix[i][cbegin]);
            cbegin++;
        }
        return list;
    }
}
