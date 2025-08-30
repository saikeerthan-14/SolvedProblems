class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        st = []
        for i in s:
            if i=="#":
                if len(st):
                    st.pop()
            else:
                st.append(i)
        k = "".join(st)
        # print(k)
        st = []
        for i in t:
            if i=="#":
                if len(st):
                    st.pop()
            else:
                st.append(i)
        # print("".join(st))
        return k == "".join(st)
        
