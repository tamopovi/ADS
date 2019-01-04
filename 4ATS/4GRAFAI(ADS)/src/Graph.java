import java.io.*;
import java.util.*;
public class Graph {
    private int numberOfVertices;
    private ArrayList<Vertex> verticesList;
    private Vertex originalVertex;
    public Graph(int numberOfVertices){
        this.numberOfVertices = numberOfVertices;
        verticesList = new ArrayList<Vertex>();
        for (int i = 0; i < this.numberOfVertices; i++){
            Vertex tempV = new Vertex(i);
            verticesList.add(tempV);
        }
    }


    public void addEdge(int receiverIndex, int senderIndex){
        Vertex sender = verticesList.get(senderIndex);
        Vertex receiver = verticesList.get(receiverIndex);
        receiver.neighbours.add(sender);
        //sender.neighbours.add(receiver);
    }

    void DFSUtil(int vertexIndex)
    {
        // Mark the current node as visited
        Vertex thisVertex = verticesList.get(vertexIndex);
        thisVertex.setVisited(true);
        System.out.println(thisVertex.number);
        // If reached vertex isn't the original, add to the "borrowing list"
        if (thisVertex != originalVertex){
            originalVertex.canBorrowList.add(thisVertex);
        }

        // Recur for all the vertices adjacent to this vertex
        ListIterator<Vertex> i = thisVertex.neighbours.listIterator();
        while (i.hasNext())
        {
            Vertex n = i.next();
            if (!n.isVisited()) {
                DFSUtil(n.number);
            }
        }
    }

    public void DFS(int vertexNumber){
        originalVertex = verticesList.get(vertexNumber);
        DFSUtil(vertexNumber);
    }

    public void printBorrowingList(){
        Iterator<Vertex> i = originalVertex.canBorrowList.listIterator();
        System.out.println(originalVertex.name + " gali skolintis is: ");
        while (i.hasNext()){
            Vertex n = i.next();
        }
    }
    public void printCanBorrowFrom(int vertexIndex){
        if(originalVertex.canBorrowList.contains(verticesList.get(vertexIndex))){
            System.out.println(originalVertex.name + " gali skolintis is " + verticesList.get(vertexIndex).name);
        }
        else
            System.out.println(originalVertex.name + " negali skolintis is " + verticesList.get(vertexIndex).name);
    }
}
