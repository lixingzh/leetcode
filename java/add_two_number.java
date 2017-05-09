// 1) java doesn't have pointer or reference
// 2) use "global variable" costs more time than "local variable". 

public class Solution_4_24{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        int val = 0;
        int v1 = 0;
        int v2 = 0;
        ListNode ret = new ListNode(0);
        ListNode node = ret;
        while(null != l1 || null != l2 || 0 != carry)
        {
            v1 = (l1 == null) ? 0:l1.val;
            v2 = (l2 == null) ? 0:l2.val;
            val = v1 + v2 + carry;
            carry = val / 10;
            node.next = new ListNode(val%10);
            node = node.next;
            
            l1 = (l1 == null)? null : l1.next;
            l2 = (l2 == null)? null : l2.next;
        }
        return ret.next;
    }
}

public class Solution_31_24 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode pre=new ListNode(0);
        ListNode curr=pre;
        int carry=0;
        while (l1!=null || l2!=null || carry!=0) {
            int v1 = l1==null ? 0 : l1.val;
            int v2 = l2==null ? 0 : l2.val;
            int sum = v1+v2+carry;
            carry = sum/10;
            curr.next = new ListNode(sum%10);
            curr = curr.next;
            l1 = l1==null ? l1 : l1.next;
            l2 = l2==null ? l2 : l2.next;
        }
        return pre.next;
    }
}