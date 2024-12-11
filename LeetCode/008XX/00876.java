//https://leetcode.com/problems/middle-of-the-linked-list/

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode one = head, two = head;
        while(two != null && two.next != null){
            one = one.next;
            two = two.next.next;
        }
        return one;
    }
}
