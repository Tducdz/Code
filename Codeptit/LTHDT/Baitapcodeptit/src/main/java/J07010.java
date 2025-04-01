
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Svien {
    private static int id = 1;
    private String ma, hoten, l, ns;
    private float gpa;

    public Svien(String hoten, String l, String ns, float gpa) {
        this.hoten = hoten;
        this.l = l;
        this.ns = ns;
        this.gpa = gpa;
        this.ma = "B20DCCN" + String.format("%03d", id++);
        if (this.ns.charAt(1) == '/') this.ns = '0' + this.ns;
        if (this.ns.charAt(4) == '/') this.ns = this.ns.substring(0, 3) + '0' + this.ns.substring(3);
    }
    
    @Override
    public String toString() {
        return ma + " " + hoten + " " + l + " " + ns + " " + String.format("%.2f", gpa);
    }
}

public class J07010 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("SV.in"));
        int n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; i++) {
            String hoten = sc.nextLine();
            String lop = sc.nextLine();
            String ns = sc.nextLine();
            float gpa = Float.parseFloat(sc.nextLine());
            Svien sv = new Svien(hoten, lop, ns, gpa);
            System.out.println(sv);
        }
    }
}