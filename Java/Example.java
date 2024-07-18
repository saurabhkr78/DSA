// import javax.swing.*;
// /* by creating object of JFrame class*/
// // public class example{
// //     public static void main(String[]args){
// //         JFrame jf=new JFrame("SwingExample");
    
// //     }
// // }
// /* By creating obj of child class Example and Prent class is JFrame and extending it*/
// public class Example extends JFrame{
//    public Example(){}
//   public Example(String s){
//      super(s); //to run a particular constructor when you dont wanna to cLL default CONSTRUCTOR
//   }
  
    
//     public static void main(String[]args){
       
//     Example ex=new Example("Swing Example");
    
//     ex.setSize(300,300);
//     ex.setVisible(true);
//     ex.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//     }
// }

//addition of two number gui
import javax.swing.*;
import java.awt.event.*;
 public class Example extends JFrame{

JLabel l1,l2,l3,l4;
JButton b1;
JTextField t1,t2;

public Example(){}
public Example(String s){
    super(s);
}
public void setComponents(){
    l1=new JLabel("Addition of two Numbers");
    l2=new JLabel("Enter First Number");
    l3 =new JLabel("Enter Second Number");
    l4=new JLabel();
    b1= new JButton("Add");
    t1 = new JTextField();
    t2 = new JTextField();
   setLayout(null);
   l1.setBounds(50,50,200,20);
   l2.setBounds(50,80,100,20);
   t1.setBounds(150,80,100,20);
   l3.setBounds(50,130,100,20);
   t2.setBounds(150,130,100,20);
   b1.setBounds(100,180,100,20);
    l4.setBounds(50,240,100,20);
    b1.addActionListener(new Handler());
    setVisible(true);
    add(l1);
    add(l2);
    add(l3);
    add(l4);
    add(t1);
    add(t2);
    add(b1);
    
}
  class Handler implements ActionListener{
  public void actionPerformed(ActionEvent e){
    int a=Integer.parseInt(t1.getText());
    int b=Integer.parseInt(t2.getText());
    int s=a+b;
    l4.setText("result is:"+s);
  }
  }

public static void main(String[]args){
    Example ex=new Example();
    ex.setComponents();
    ex.setSize(300,300);
    ex.setVisible(true);
    ex.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
 }