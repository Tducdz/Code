
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

class sVien {
    private String m = "B20DCCN001", t, l, ns;
    private float gpa;
    
    public sVien() {
        t = "";
        l = "";
        ns = "";
        gpa = 0;
    }

    public sVien(String t, String l, String ns, float gpa) {
        this.t = t;
        this.l = l;
        this.ns = ns;
        this.gpa = gpa;
    }
    
    public String formatns() {
        try {
            SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
            Date date = formatter.parse(ns);
            return formatter.format(date);
        } catch (ParseException e) {
            System.out.println("");
        }
        return "";
    }
    
    @Override
    public String toString() {
        return m + " " + t + " " + l + " " + formatns() + " " + String.format("%.2f", gpa);
    }
}

public class J04006 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String b = sc.next();
        String c = sc.next();
        float d = sc.nextFloat();
        sVien e = new sVien(a, b, c, d);
        System.out.println(e);
    }
}