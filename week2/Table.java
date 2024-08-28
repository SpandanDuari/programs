import java.util.*;
class Table{
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter a number");
        int n=in.nextInt();
        in.close();
        for(int i=1;i<=10;i++){
            System.out.println((i*n));
        }
        
    }
}