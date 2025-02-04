class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        n = len(words)
        for i in range(n-1):
            cur = words[i]
            nxt = words[i + 1]
            flag = False
            for j in range(min(len(cur),len(nxt))):
                pos_x = -1
                pos_y = -1
                for k in range(26):
                    if order[k] == cur[j]:
                        pos_x = k
                    if order[k] == nxt[j]:
                        pos_y = k
                if pos_x < pos_y:
                    flag = True
                    break
                if pos_x > pos_y:
                    return False
            if not flag:
                if len(cur) > len(nxt):
                    return False
                min_len = len(cur)
                if cur[:min_len] != nxt[:min_len]:
                    return False
        return True
        
