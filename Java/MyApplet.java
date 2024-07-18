// import java.applet.Applet;
// // <applet code="My Applet" width="300" height="200">   </applet>
// public class MyApplet extends Applet {
//    public void paint(Graphics g){
//     g.drawString("B6IX.com",100,100);
//    } 
// }
import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionListener;
// <applet code="My Applet" width="100" height="80"> </applet>
public  class MyApplet extends Applet{
Label l1;
Label l2;
Label l3;
TextField t1;
TextField t2;
Button b1;

public void init(){
    //to override Init function of Applet Class
    l1=new Label("First Number");
    l2=new Label("Second Number");
    t1=new TextField();
    t2=new TextField();
    b1=new Button("Add");
    l3=new Label();

    setLayout(null);

    l1.setBounds(30,50,100,20);
    l2.setBounds(30,100,100,20);
    l3.setBounds(30,180,100,20);
    t1.setBounds(150,50,100,20);
    t2.setBounds(150,100,100,20);
    b1.setBounds(150,100,100,20);

    add(l1);
    add(l2);
    add(t1);
    add(t2);
    add(b1);
    add(l3);
    b1.addActionListener(new MyHandler());
}
public class MyHandler implements ActionListener{
    public void actionPerformed(actionEvent e){//overridding function of ActionListener CLass
        int a,b,s;
        a=Integer.parseInt(t1.getText());
        b=Integer.parseInt(t2.getText());
        s=a+b;
        l3.setText("Sum is:"+s);
    }
}
}
