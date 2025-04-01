
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class J07005 {
    public static void main(String args[]) throws FileNotFoundException, IOException {
        DataInputStream dis = new DataInputStream(new FileInputStream("DATA.in"));
        int[] a = new int[1000];
        for (int i = 0; i < 100000; i++) {
            a[dis.readInt()]++;
        }
        for (int i = 0; i < 1000; i++) {
            System.out.println(i + " " + a[i]);
        }
    }
}
