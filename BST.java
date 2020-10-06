public class BST{
    //tree node class
    static class Node{
        int val;    //data of node
        Node left,right;    //children 
        public Node(int val){   //constructor
            this.val=val;
            left=right=null;
        }
        //count nodes
        static int countNodes(Node root){
            if(root==null)  //empty tree
                return 0;
            return 1+countNodes(root.left)+countNodes(root.right);  //left subtree + right subtree + root
        }
        static int levels(Node root){
            if(root==null)  //empty tree
                return 0;
            return 1+Math.max(levels(root.left),levels(root.right));        //level is same as height so maximum of both subtree
        }
        static int countLeaf(Node root){
            if(root==null)  //empty tree
                return 0;
            if(root.left==null && root.right==null)     //leaf node
                return 1;
            return countLeaf(root.left)+countLeaf(root.right);  //total leaf nodes in both subtree
        }
        public static void main(String[] args) {
            //creating tree as mentioned in input diagram
            Node root=new Node(4);
            root.left=new Node(1);
            root.right=new Node(6);
            root.left.left=new Node(0);
            root.left.right=new Node(2);
            root.left.right.right=new Node(3);

            root.right.left=new Node(5);
            root.right.right=new Node(7);
            root.right.right.right=new Node(8);
            //testing functions
            System.out.println("Total Nodes: "+countNodes(root));
            System.out.println("Total Levels: "+levels(root));
            System.out.println("Total Leaf Nodes: "+countLeaf(root));

        }
    }
}