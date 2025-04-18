
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

class WordSet {
    private Set<String> set;
    
    public WordSet(String filename) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(filename));
        set = new TreeSet<>();
        while (sc.hasNext()) {
            set.add(sc.next().toLowerCase());
        }
    }
    
    @Override
    public String toString() {
        String s = "";
        for (String i : set) {
            s += i + "\n";
        }
        return s;
    }
}

public class J07007 {
    public static void main(String[] args) throws FileNotFoundException {
        WordSet ws = new WordSet("VANBAN.in");
        System.out.println(ws);
    }
}