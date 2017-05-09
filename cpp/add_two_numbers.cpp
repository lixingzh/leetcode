/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_100{
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 and !l2) return NULL;
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *ret = NULL, *origRet = NULL;
        int car = 0;
        while (l1 and l2) {
            int sum = l1->val + l2->val + car;
            car = sum / 10;
            assert(car <= 1);
            sum %= 10;
            ListNode* node = new ListNode(sum);
            if (!origRet) {
                origRet = ret = node;
            } else {
                ret->next = node;
                ret = ret->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* remain = l1 ? l1 : l2;
        while (remain) {
            int sum = car + remain->val;
            car = sum / 10;
            sum = sum % 10;
            ret->next = new ListNode (sum);
            remain = remain->next;
            ret = ret->next;
        }
        if (car) {
            ret->next = new ListNode(car);
        }
        return origRet;
    }
};

class Solution_97.2 {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = nullptr, *head = nullptr;
        int v1 = 0, v2 = 0, carry = 0, sum = 0;
        while(nullptr != l1 || nullptr != l2 || 0 != carry)
        {
            v1 = (nullptr == l1)? 0 : l1->val;
            v2 = (nullptr == l2)? 0 : l2->val;
            sum = v1 + v2 + carry;
            carry = sum / 10;
            if(nullptr == head)
            {
                head = new ListNode(sum % 10);
                cur = head;
            }
            else
            {
                cur->next = new ListNode(sum % 10);
                cur = cur->next;
            }
            l1 = (nullptr == l1)? nullptr : l1->next;
            l2 = (nullptr == l2)? nullptr : l2->next;
        }
        return head;
    }
};