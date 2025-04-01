
import java.util.Scanner;

class nVien {
    private String ma = "00001", ht, gt, ns, dc, mst, nkhd;

    public nVien(String ht, String gt, String ns, String dc, String mst, String nkhd) {
        this.ht = ht;
        this.gt = gt;
        this.ns = ns;
        this.dc = dc;
        this.mst = mst;
        this.nkhd = nkhd;
    }

    @Override
    public String toString() {
        return ma + " " + ht + " " + gt + " " + ns + " " + mst + " " + nkhd;
    }
}
public class J04007 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        nVien nv = new nVien(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());
        System.out.println(nv);
    }
}
