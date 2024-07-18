import java.util.Scanner;

public class nth_prime {
public static void main(String arg[]){
    int i,n,counter, j;
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter the n value : ");
    n=scanner.nextInt();
    System.out.print("Prime numbers between 1 to 10 are ");
    for(j=2;j<=n;j++){
       counter=0;
       for(i=1;i<=j;i++){
          if(j%i==0){
             counter++;
          }
       }
       if(counter==2)
       System.out.print(j+" ");
    }
 }
}