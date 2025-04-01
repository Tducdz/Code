
import java.util.Scanner;

class thiSinh {
    private String hoten, ngaysinh;
    private Double diem1, diem2, diem3, tong;

    public thiSinh(String hoten, String ngaysinh, Double diem1, Double diem2, Double diem3) {
        this.hoten = hoten;
        this.ngaysinh = ngaysinh;
        this.diem1 = diem1;
        this.diem2 = diem2;
        this.diem3 = diem3;
        this.tong = diem1 + diem2 + diem3;
    }
    
    @Override
    public String toString() {
        return hoten + " " + ngaysinh + " " + String.format("%.1f", tong);
    }
}
public class J04005 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String b = sc.nextLine();
        Double c = sc.nextDouble();
        Double d = sc.nextDouble();
        Double e = sc.nextDouble();
        thiSinh t = new thiSinh(a, b, c, d, e);
        System.out.println(t);
    }
}
