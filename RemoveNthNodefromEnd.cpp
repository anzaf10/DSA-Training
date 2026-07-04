//leetcode - 19//

class Solution {
    int getLength(ListNode* head) {
        int counter = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }

        return counter;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);

   
        if (length - n == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int pos = length - n;
        ListNode* temp = head;

        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};
