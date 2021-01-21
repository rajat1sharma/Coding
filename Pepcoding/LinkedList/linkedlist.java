public class linkedlist{
    
    private class Node{
        private int data=0;
        private Node next=null;
        
        Node(int data){
            this.data=data;

        }
    }

    private Node Head=null;
    private Node Tail=null;
    private int NumberOfNodes=0;

    public int size(){
        return this.NumberOfNodes;
        //this signify class mein banaye gye variables
    }
    
    public boolean isEmpty(){
        return NumberOfNodes==0;
    }

    //making more function to handle the program making it more effective 
    //and stopping it to completely stop working
}