/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * result = NULL;
    struct ListNode * temp = NULL;
    struct ListNode * cur = NULL;

    int carry, sum;
    carry = 0;
    while(l1 || l2)
    {
        sum = carry + (l1? l1->val: 0) + (l2? l2->val: 0);
        if(sum>=10)
        {
            carry = 1;
        }
        else
            carry = 0;
        sum = sum %10;
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = sum;
        if(cur)
            cur->next = temp;
        cur = temp;
        if(!result)
            result = temp;
        

        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;

    }
    if(carry == 1)
    {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = carry;
        cur->next = temp;
    }

    return result;
}