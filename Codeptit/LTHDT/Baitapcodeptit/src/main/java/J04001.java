//
//import java.time.temporal.Temporal;
//import java.util.Scanner;
//
//class Point {
//    private double x;
//    private double y;
//
//    public Point() {
//        x = 0;
//        y = 0;
//    }
//
//    public Point(double x, double y) {
//        this.x = x;
//        this.y = y;
//    }
//    
//    public Point(Point p) {
//        this.x = p.x;
//        this.y = p.y;
//    }
//
//    public double getX() {
//        return x;
//    }
//
//    public void setX(double x) {
//        this.x = x;
//    }
//
//    public double getY() {
//        return y;
//    }
//
//    public void setY(double y) {
//        this.y = y;
//    }
//    
//    public double distance(Point p) {
//        return Math.sqrt(Math.pow(this.x - p.x, 2) + Math.pow(this.y - p.y, 2));
//    }
//    
//    public double distance(Point a, Point b) {
//        return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
//    }
//    
//    @Override
//    public String toString() {
//        return x + " " + y;
//    }
//}
//public class J04001 {
//    public static void main(String args[]) {
//        Scanner sc = new Scanner(System.in);
//        int t = sc.nextInt();
//        while (t-- > 0) {
//            Point a = new Point(sc.nextDouble(), sc.nextDouble());
//            Point b = new Point(sc.nextDouble(), sc.nextDouble());
//            Point temp = new Point();
//            System.out.printf("%.4f\n", temp.distance(a, b));
//        }
//    }
//}
