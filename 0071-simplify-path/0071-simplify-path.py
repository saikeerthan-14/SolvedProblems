class Solution:
    def simplifyPath(self, path: str) -> str:
        path = [i for i in path.split("/") if i!=""]

        prev = ""
        ans=[]
        for i in range(len(path)):
            ans.append(path[i])
            if path[i] == "..":
                # print(ans)
                ans.pop()
                if len(ans):
                    ans.pop()
                # print(ans)
            elif path[i] == ".":
                ans.pop()

            
            
        
        # print(ans)
        return "/" + "/".join(ans)