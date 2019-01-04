import javax.print.DocFlavor;
import java.util.ArrayList;

public class Main {
    public static void main(String args[]){
        Graph g = new Graph(6);
        /*
        g.addEdge(0,1); //a-b
        g.addEdge(0,2); //a-s
        g.addEdge(2,3); //s-c
        g.addEdge(3,4); //c-d
        g.addEdge(3,5); //c-e
        g.addEdge(3,6); //c-f
        g.addEdge(2,7); //s-g
        g.addEdge(5,8); //e-h
        g.addEdge(3,5); //c-e
        g.addEdge(7,8); //g-h*/
        // 0-a, 1-b, 2-s, 3-c, 4-d, 5-e, 6-f, 7-g, 8-h
        //ABSCDEHGF
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 1);
        g.addEdge(2, 3);
        g.addEdge(2, 4);
        g.addEdge(4, 5);
        g.DFS(2);
        //g.printBorrowingList();
        //g.printCanBorrowFrom(1);

        //turi lapeli kuprinej, kad parodytum kaip veikia
    }
}