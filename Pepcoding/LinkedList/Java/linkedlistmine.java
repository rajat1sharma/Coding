public class linkedlistmmine{
    private class Node{
        private int data=0;
        private Node next=null;
        Node(int data)
        {
            this.data=data;
        }
    }
    private Node head=null;
    private Node tail=null;
    private int numberofelements=0;

    public int size()
    {
        return this.numberofelements;
    }

    public boolean isEmpty()
    {
        return this.size()==0;
    }
    public void handelZeroSize(Node node)
    {
        this.head=node;
        this.tail=node;
    }
    protected void addFirstNode(Node node)
    {
        if(size()==0)
        handelZeroSize(node);
        else{
            node.next=this.head;
            this.head=node;
        }
        this.numberofelements++;

    }
    public void addFirst(int data)
    {
        Node node=new Node(data);
        addFirstNode(node);
    }

    protected void addLastNode(Node node)
    {
        if(size()==0)
        handelZeroSize(node);
        else
        {
            tail.next=node;
            tail=node;
        }
        this.numberofelements++;
    }
    public void addLast(int data)
    {
        Node node=new Node(data);
        addLastNode(node);
    }
    protected Node getNodeAt(int idx)
    {
        Node temp=this.head;
        while(idx-->0)
        {
            temp=temp.next;
        }
        return temp;
    }
    protected void addNodeAt(Node node,int idx)
    {
        if(idx==0)
        addFirstNode(node);
        else if(idx==size())
        addLastNode(node);//to update tail
        else
        {
            Node prev=getNodeAt(idx-1);
            Node fow=prev.next;
            prev.next=node;
            node.next=fow;
        }
        this.numberofelements++;
    }
    public void addAt(int data,int idx) throws Exception
    {
        if(idx<0||idx>size())
        {
            throw new Exception("invalid index");
        }
        Node node=new Node(data);
        addNodeAt(node,idx);
    }
    public void handelSize1()
    {
        this.head=null;
        this.tail=null;
    }
    protected Node removeFirstNode()
    {
        Node temp=head; 
        if(size()==1)
            handelSize1();
        else
            head=head.next;
        temp->next=null;
        this.numberofelements--;
        return temp;    
    }
    public int removeFirst() throws Exception{
        if(size()==0)
        throw new Exception("invalid size");
        else
        {
            Node node=removeFirstNode();
            return node.data;

        }
    }
    protected Node removeLastNode()
    {
        Node temp=tail;
        if(size()==1)
        handelSize1();
        else
        {
            Node secondlast=getNodeAt(size()-2);
            secondlast.next=null;
            tail=secondlast;
        }
        this.numberofelements--;
        return temp;
    }
    public int removeLast() throws Exception{
        if(size()==0)
        throw new Exception("linked lis is empty");
        else
        {
            Node node=removeLastNode();
            return node.data;
        }
    }
}