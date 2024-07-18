import java.util.Scanner;
public class university {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String type;
        System.out.println("Enter Student type(online/offline)?");
        type = sc.nextLine();
        
        String name;
        int UID;
        int hours;
        String PaymentStatus;
        
        if (type.equals("online")) {
            System.out.println("Enter Name");
            name = sc.nextLine();
            System.out.println("Enter UID");
            UID = sc.nextInt();
            sc.nextLine(); 
            System.out.println("Enter Hours of Contact");
            hours = sc.nextInt();
            sc.nextLine(); 
            System.out.println("Enter PaymentStatus");
            PaymentStatus = sc.nextLine();
            
            Online o1 = new Online();
            o1.general(name, UID, hours,PaymentStatus );
            o1.show();
        }
        else if (type.equals("offline"))
         {
            System.out.println("Enter Name");
            name = sc.nextLine();
            System.out.println("Enter UID");
            UID = sc.nextInt();
            sc.nextLine(); 
            System.out.println("Enter Hours on Contact");
            hours = sc.nextInt();
            sc.nextLine(); 
            System.out.println("Enter PaymentStatus");
            PaymentStatus = sc.nextLine();
            
            Offline o2 = new Offline();
            o2.general(name, UID, hours, PaymentStatus);
            o2.show();
        }
    }
}

class Online {
    String name;
    int UID;
    int hours;
    String PaymentStatus;

    void general(String name, int UID, int hours, String PaymentStatus) 
    {
        this.name = name;
        this.UID = UID;
        this.hours = hours;
        this.PaymentStatus = PaymentStatus;
    }
    void show()
    {
        System.out.println("This is an online Student");
        System.out.println("Name: " + name);
        System.out.println("UID: " + UID);
        System.out.println("Hours of Contact: " + hours);
        System.out.println("PaymentStatus: " + PaymentStatus);
        System.out.println();
    }
    
}

class Offline 
{
    String name;
    int UID;
    int hours;
    String PaymentStatus;

    void general(String name, int UID, int hours, String state) 
    {
        this.name = name;
        this.UID = UID;
        this.hours = hours;
        this.PaymentStatus = PaymentStatus;
    }
 
    void show()
    {
        System.out.println("This is an Offline Student");
        System.out.println("Name: " + name);
        System.out.println("UID: " + UID);
        System.out.println("Hours of Contact: " + hours);
        System.out.println("PaymentStatus: " + PaymentStatus);
        System.out.println();
    }
}