import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;

public class Vertex {
    public String name;
    public int number;
    public ArrayList<Vertex> canBorrowList;
    public LinkedList<Vertex> neighbours;
    public boolean visited;
    public Vertex(int index){
        this.canBorrowList = new ArrayList<Vertex>();
        this.neighbours = new LinkedList<>();
        this.number = index;
        this.name = returnName(index);
        this.visited = false;
    }

    public void setVisited(boolean visited) {
        this.visited = visited;
    }

    public boolean isVisited() {
        return visited;
    }

    public String returnName(int index){
        ArrayList<String> nameList = new ArrayList<String>();
        nameList.add("Jonas");
        nameList.add("Greta");
        nameList.add("Giedre");
        nameList.add("Petras");
        nameList.add("Maryte");
        nameList.add("Emilija");
        nameList.add("Ona");
        nameList.add("Juozas");
        nameList.add("Antanas");
        nameList.add("Juste");
        nameList.add("Kazys");
        nameList.add("Tomas");
        return nameList.get(index);
    }
}
