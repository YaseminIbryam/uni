#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:

    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* currNode = head;
        while (currNode) {
            ++n;
            currNode = currNode->next;
        }
        currNode = head;
        // if (n == 2) {
        //     return currNode->val + currNode->next->val;
        // }
        for (int i = 0; i < n / 2; ++i) {
            currNode = currNode->next;
        }
        ListNode* previous = nullptr;
        while (currNode) {
            ListNode* next = currNode->next;
            currNode->next = previous;
            previous = currNode;
            currNode = next;
        }
        currNode = previous;
        int maxSum = INT_MIN;
        while (currNode && head) {
            int sum = currNode->val + head->val;
            if (sum > maxSum) {
                maxSum = sum;
            }
            currNode = currNode->next;
            head = head->next;
        }
        return maxSum;
    }
};



//int main() {
//    ListNode* head = new ListNode(5);
//    head->next = new ListNode(4);
//    head->next->next = new ListNode(2);
//    head->next->next->next = new ListNode(1);
//
//    Solution sol;
//    std::cout << "Max twin sum: " << sol.pairSum(head) << std::endl;
//
//    ListNode* current = head;
//    while (current) {
//        ListNode* nextNode = current->next;
//        delete current;
//        current = nextNode;
//    }
//
//    return 0;
//}