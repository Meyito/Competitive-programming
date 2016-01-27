import java.util.Scanner;
 
 
public class Main{
     
    public static void main(String [] args){
        Scanner sc=new Scanner(System.in);
        float a=sc.nextFloat(),b=sc.nextFloat();
         
        float f=((a*3.5f)+(b*7.5f))/11;
        System.out.print("MEDIA = ");
        System.out.printf("%.5f", f);
        System.out.println("");
         
    }
     
}