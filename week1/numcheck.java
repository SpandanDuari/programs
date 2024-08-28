import java.util.*;
class numcheck{
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int num;
        System.out.println("Enter a number");
        num=in.nextInt();
        if(num>0){
            System.out.println("The number is positive");

        }
        else if(num<0){
            System.out.println("The number is negative");

        }
    
        else {
            System.out.println("The number is zero");

        }
        in.close();
    }
}