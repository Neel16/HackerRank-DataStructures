//LeetCode Odd Even linked List.
//Separate a given linked list in such a way that all odd nodes appear first and all even appear last.
// 1->2->3->4->5

//out: 1->3->5->2->4

ListNode* oddEvenList(ListNode* head) {
        
        if(head == nullptr)
            return head;
        ListNode* headRef = head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenRef = head->next;
        
        
        while(even && even->next)
        {
            odd->next = even->next;
            odd=odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
       // even->next=nullptr;
        odd->next= evenRef;
        
        return head;
        
    }