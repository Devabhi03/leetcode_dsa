#User function Template for python3
class Node:
    
    def __init__(self):
        self.children=[None]*26
        self.isEnd=False

class Trie:
    
    def __init__(self):
        self.root=Node()

    def insert(self, word: str):
        curr=self.root
        for w in word:
            i=ord(w)-ord("a")
            if curr.children[i]==None:
                curr.children[i]=Node()
            curr=curr.children[i]
        curr.isEnd=True

    def search(self, word: str) -> bool:
        curr=self.root
        for w in word:
            i=ord(w)-ord("a")
            if curr.children[i]==None:
                return False
            curr=curr.children[i]
        return curr.isEnd

    def isPrefix(self, word: str) -> bool:
        curr=self.root
        for w in word:
            i=ord(w)-ord("a")
            if curr.children[i]==None:
                return False
            curr=curr.children[i]
        return True

#{ 
 # Driver Code Starts
def main():
    t = int(input())
    for _ in range(t):
        q = int(input())
        ans = []
        trie = Trie()

        for _ in range(q):
            x, s = input().split()
            x = int(x)

            if x == 1:
                trie.insert(s)
            elif x == 2:
                ans.append(trie.search(s))
            elif x == 3:
                ans.append(trie.isPrefix(s))

        # Print results as lowercase true/false
        print(" ".join(["true" if res else "false" for res in ans]))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends