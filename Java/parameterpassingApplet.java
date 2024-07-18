//passing parameter to applet
import java.applet.Applet;
import java.awt.*;
/*<applet code="MyApplet" width="300" height="200"> 
<Param name="Site" value="B6IX.com"/> 
</applet>*/

private String defaultMessage="Hello";
class MyApplet extends Applet{
    public void paint(Graphic g){
      String s=this.getParameter("Site");
      if(s=null){
        s=defaultMessage();

        g.drawString(s,50,20);
      }
    }