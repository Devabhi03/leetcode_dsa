class Solution:
    def isPalindrome(self, head):
        #code here
        vals = []
        while head:
            vals.append(head.data)
            head = head.next
        return vals == vals[::-1]
def create_linked_list(arr):
    head = Node(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = Node(val)
        curr = curr.next
    return head