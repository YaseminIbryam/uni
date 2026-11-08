#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    std::size_t size(const ListNode* head) {
        std::size_t size = 0;
        while (head) {
            ++size;
            head = head->next;
        }
        return size;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::size_t size1 = size(l1);
        std::size_t size2 = size(l2);
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        if (size1 < size2) {
            head1 = l2;
            head2 = l1;
            std::size_t temp = size1;
            size1 = size2;
            size2 = temp;
        }
        if (!head1) {
            return head1;
        }
        ListNode* ten = nullptr;
        ListNode* currNode = new ListNode(0, head1);
        ListNode* head = currNode;
        for (std::size_t i = 0; i < size1 - size2; ++i) {
            if (currNode->next)
                currNode = currNode->next;
        }
        while (head2) {
            ListNode* next = currNode->next;
            int sum = next->val + head2->val;
            // it can't be more than 19?
            if (sum >= 10) {
                ++currNode->val; //try brackets if it doesn't work or maybe sum / 10
                sum %= 10;
                if (currNode->val == 10) {
                    ten = currNode;
                }
            }
            next->val = sum;
            currNode = next;
            head2 = head2->next;
        }
        if (!ten) {
            if (head->val != 0)
                return head;
            return head1;
        }
        currNode = head1;

        bool isThereTen = true;
        while (isThereTen) {
            if (currNode->val == 10) {
                currNode->val = 0;
                head1 = new ListNode(1, currNode);
            }
            else {
                while (currNode && currNode->next != ten) {
                    currNode = currNode->next;
                }
                ++currNode->val;
                currNode->next->val = 0;
            }
            if (currNode->val == 10) {
                ten = currNode;
            }
            else {
                isThereTen = false;
            }
            currNode = head1;
        }
        if (head->val != 0) {
            return head;
        }
        return head1;

    }
};

int main() {
    //[7,0,4,4,8,5,0,6]
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(0);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(8);
    l1->next->next->next->next->next = new ListNode(5);
    l1->next->next->next->next->next->next = new ListNode(0);
    l1->next->next->next->next->next->next->next = new ListNode(6);
    //[9,9,3,1,9,7,8,9,5]
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(3);
    l2->next->next->next = new ListNode(1);
    l2->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next = new ListNode(7);
    l2->next->next->next->next->next->next = new ListNode(8);
    l2->next->next->next->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next->next->next->next = new ListNode(5);

    
    //ListNode* l1 = new ListNode(8);
    //l1->next = new ListNode(9);
    //l1->next->next = new ListNode(9);
    //
    //ListNode* l2 = new ListNode(2);

    Solution sol;
    ListNode* head = sol.addTwoNumbers(l1, l2);

    while (head) {
        std::cout << head->val;
        head = head->next;
    }

    ListNode* current = l1;
    while (current) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    current = l2;
    while (current) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}