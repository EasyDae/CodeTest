class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        boolean[] seen = new boolean[201];

        ListNode list = new ListNode(0);
        ListNode cur = list;
        
        while (head != null) {
            int val = head.val + 100;
            if (!seen[val]) {
                seen[val] = true;
                cur.next = new ListNode(head.val);
                cur = cur.next;
            }
            head = head.next;
        }
        
        return list.next;
    }
}
