
import java.util.Scanner;

class  PhanSos {
    private long tu;
    private long mau;

    public PhanSos() {
    }

    public PhanSos(long tu, long mau) {
        this.tu = tu;
        this.mau = mau;
    }

    public long getTu() {
        return tu;
    }

    public void setTu(long tu) {
        this.tu = tu;
    }

    public long getMau() {
        return mau;
    }

    public void setMau(long mau) {
        this.mau = mau;
    }
    
    public static long ucln(long a, long b) {
        if (b == 0) return a;
        return ucln(b, a % b);
    }
    
    public PhanSos rutgon() {
        long t = ucln(this.tu, this.mau);
        this.tu /= t;
        this.mau /= t;
        return this;
    }
    
    public PhanSos tong(PhanSos p) {
        long bc = this.mau * p.getMau() / ucln(this.mau, p.getMau());
        PhanSos t = new PhanSos(1, 1);
        t.tu = bc / this.mau * this.tu + bc / p.getMau() * p.getTu();
        t.mau = bc;
        t.rutgon();
        return t;
    }
    
    @Override
    public String toString() {
        return tu + "/" + mau;
    }
}
public class J04004 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        long d = sc.nextLong();
        PhanSos p = new PhanSos(a, b);
        PhanSos q = new PhanSos(c, d);
        p.rutgon();
        q.rutgon();
        p = p.tong(q);
        System.out.println(p);
    }
}
