class TreeNode:
    def __init__(self, name: str):
        self.node_name = name
        self.children = {}
        self.is_file = False
        self.content = ""

class FileSystem:

    def __init__(self):
        self.head = TreeNode("/")

    def filter_path(self, path: List[str]) -> List[str]:
        filtered = []
        for x in path:
            if x!="":
                filtered.append(x)
        
        return filtered

    def ls(self, path: str) -> List[str]:
        # get the directories in the path and make sure the starting point is /
        path = path.lstrip("/").split("/")
        path = self.filter_path(path)

        cur_node = self.head

        # Traverse the directory
        for directory in path:
            cur_node = cur_node.children[directory]
        
        if cur_node.is_file:
            return [cur_node.node_name]

        # return lexicographical order
        return list(sorted(cur_node.children.keys()))

    def mkdir(self, path: str) -> None:
        cur_node = self.head
        path = path.lstrip("/").split("/")
        path = self.filter_path(path)

        # Traverse and create along directories
        for directory in path:
            if directory not in cur_node.children:
                cur_node.children[directory] = TreeNode(directory)
            cur_node = cur_node.children[directory]


    def addContentToFile(self, filePath: str, content: str) -> None:
        
        cur_node = self.head
        path = filePath.lstrip("/").split("/")
        path = self.filter_path(path)

        for directory in path:
            if directory not in cur_node.children:
                cur_node.children[directory] = TreeNode(directory)
            cur_node = cur_node.children[directory]
        
        # Mark the treenode as a file
        cur_node.is_file = True
        cur_node.content += content




    def readContentFromFile(self, filePath: str) -> str:
        
        cur_node = self.head

        path = filePath.lstrip("/").split("/")
        path = self.filter_path(path)

        for directory in path:
            cur_node = cur_node.children[directory]
        
        return cur_node.content


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)