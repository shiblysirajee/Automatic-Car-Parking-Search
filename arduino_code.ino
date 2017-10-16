#include <SPI.h>
#include <Ethernet.h>
#include <Servo.h>



Servo microservo1;
Servo microservo2;
Servo microservo3;
Servo microservo4;

int randNumber;

String myRand[4]={"1111","2222","3333","4444"};

 bool IsLock= true;
 
 int Row1;
 int Row2;
 int Row3;
 int Row4;

 int check1=1;
 int check2=1;
 int check3=1;
 int check4=1;

 String w1=" ";
 String w2=" ";
 String w3=" ";
 String w4=" ";

int pos = 0;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //physical mac address
byte ip[] = { 10,0,0,5};                      // ip in lan (that's what you need to use in your browser. ("192.168.1.178")

EthernetServer server(80);                             //server port
String readString;

void setup() {

  
  Serial.begin(9600);
  
  microservo1.attach(9);
  microservo1.write(0);
  
  microservo2.attach(7);
  microservo2.write(0);

  microservo3.attach(6);
  microservo3.write(0);

  microservo4.attach(5);
  microservo4.write(0);
  
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  
  
}


void loop() {
  
  // Create a client connection
  
  boolean currentLineIsBlank = true;
  EthernetClient client = server.available();
  
      if (client) {
        while (client.connected()) 
        {
          if (client.available()) {
          char c = client.read();

        //read char by char HTTP request
          if (readString.length() < 100) {
          //store characters to string
          readString += c;
          //Serial.print(c);
        }

        //if HTTP request has ended
        if (c == '\n' && currentLineIsBlank) {
          Serial.println(readString); //print to serial monitor for debuging
          
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no\">");
          client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
          client.println("<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css\">");
          //<!-- Optional theme -->
          client.println("<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap-theme.min.css\">");
          //<!-- Latest compiled and minified JavaScript -->
          client.println("<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js\"></script>");

          client.println("<TITLE>Arduino To Web</TITLE>");
          client.println("</HEAD>");

          //SERVO 

          String result1;
          int LDR1 = analogRead(A0);
          
          if(LDR1<200)
          {
                result1="Car Parked SUCCESSFULLY.";
                delay(100);
                microservo1.write(90);  
              
              if(check1==1)
              {
                  Row1=1;
                  check1++;   
              }      
            }
            
            else
            {
                  check1=1;
                  result1="This Slot is EMPTY.";
                  delay(100);
                  microservo1.write(0);                
            }

          String result2;
          int LDR2 = analogRead(A1);

          if(LDR2<200)
          {
                result2="Car Parked SUCCESSFULLY.";
                microservo2.write(90);
                if(check2==1)
                {  
                    Row2=1;
                    check2++;   
                } 
            }
            else
            {
                  check2=1;
                  result2="This Slot is EMPTY.";
                  microservo2.write(0);
              }
              

           String result3;
           int LDR3 = analogRead(A2);
           if(LDR3<200)
            {
                result3="Car Parked SUCCESSFULLY.";
                microservo3.write(90);
                if(check3==1)
                {
               
                    Row3=1;
                    check3++;   
                } 
            }
            else
            {
                check3=1;
                result3 = "This Slot is EMPTY.";
                microservo3.write(0);
              }

          String result4;
          int LDR4 = analogRead(A3);

          if(LDR4<200)
          {
              result4="Car Parked SUCCESSFULLY.";
              microservo4.write(90);
              if(check4==1)
              {
               
                 Row4=1;
                 check4++;   
               } 
            }
            else
            {
               check4=1;
               result4="This Slot is EMPTY.";
               microservo4.write(0);
            }

           
          
          client.println("<BODY>");
          client.println("<center>");
          client.println("<H1>Smart Car Parking System</H1>");
          client.println("<hr />");
          client.println("<br/> <br />");
        
          if (readString.indexOf("pin1=1111") > 0) 
          {
                 microservo1.write(0);
                 w1 = "";            
          }
                
           else if(readString.indexOf("pin1=") > 0)
           {
                  w1 = "Wrong Pin 1";
           }
          
           if (readString.indexOf("pin=2222") > 0) 
           {          
                  microservo2.write(0);
                  w2="";              
           }
                
           else if(readString.indexOf("pin2=") > 0)
              {
                  w2 = "Wrong Pin 2";
               }
          
             if (readString.indexOf("pin3=3333") > 0) 
             {
                  microservo3.write(0);
                  w3="";               
               }
                
            else if(readString.indexOf("pin3=") > 0)
              {
                  w3 = "Wrong Pin 3";
               }

           if (readString.indexOf("pin=4444") > 0) {
              
                  microservo4.write(0);
                  w4="";
                 
                }
                
            else if(readString.indexOf("pin4=") > 0)
              {
                  w4 = "Wrong Pin 4";
              }
           
          //clearing string for next read
          readString = "";
             
          client.println("<table class=\"table table-condensed\">");
          client.println("<tr>");
          client.println("<th>");
          client.println("Parking SPACE NO: &nbsp; &nbsp;");
          client.println("</th>");
          
          client.println("<th>");
          client.println("Parking STATUS: &nbsp; &nbsp;");
          client.println("</th>");
          client.println("<th>");
          client.println("PIN: &nbsp; &nbsp;");
          client.println("</th>");
          
          client.println("<th>");
          client.println("Unlock CAR: &nbsp; &nbsp;");
          client.println("</th>");          
          client.println("</tr>");
          
          client.println("<tr class=\"warning\">");
          client.println("<td>");
          client.print("101 &nbsp;&nbsp;&nbsp;&nbsp;");
          client.println("</td>");
          client.println("<td>");
          client.print("<strong>");
          client.print(result1);
          client.print("</strong>");
          client.println("</td>");

          client.println("<td>");  
          if(Row1==1)
          {
           client.print(myRand[0]);
           Row1++;
          }
         client.println("</td>");
                 
         client.println("<td>");
         client.println("<form action='/' method=get>");
         client.print("<INPUT TYPE=TEXT NAME='pin1' VALUE='' SIZE='15' MAXLENGTH='15'>");  
         client.println("<INPUT TYPE=SUBMIT NAME='submit' VALUE='Enter Unlock PIN'>");
         client.println("</form>");     
         client.println("</td>");
         client.print("<td>");
         
         client.println("<span class=\"label label-danger\">");
         client.print(w1);
         client.println("</span>");
         client.print("</td>");
         client.println("</tr>");

          client.println("<tr class=\"success\">");
          client.println("<td>");
          client.print("102 &nbsp;&nbsp;&nbsp;&nbsp;");
          client.println("</td>");
          client.println("<td>");
          client.print("<strong>");
          client.print(result2);
          client.print("</strong>");
          client.println("</td>");
          
           
          client.println("<td>");    
         if(Row2==1)
         {
            client.print(myRand[1]);
            Row2++;
          }
          client.println("</td>");
          
         client.println("<td>");         
         client.println("<form action='/' method=get>");
         client.print("<INPUT TYPE=TEXT NAME='pin2' VALUE='' SIZE='15' MAXLENGTH='15'>");  
         client.println("<INPUT TYPE=SUBMIT NAME='submit' VALUE='Enter Unlock PIN'>");
         client.println("</form>");           
         client.println("</td>");
         
         client.print("<td>");
         client.println("<span class=\"label label-danger\">");
         client.print(w2);
         client.println("</span>");
         client.print("</td>");
          client.println("</tr>");

          client.println("<tr class=\"warning\">");
          client.println("<td>");
          client.print("103 &nbsp;&nbsp;&nbsp;&nbsp;");
          client.println("</td>");
          
          client.println("<td>");
          client.print("<strong>");
          client.print(result3);
          client.print("</strong>");
          client.println("</td>");
          
          
          client.println("<td>");          
          if(Row3==1)
          {
              client.print(myRand[2]);
              Row3++;
          }
         client.println("</td>");
         
         client.println("<td>");
         client.println("<form action='/' method=get>");
         client.print("<INPUT TYPE=TEXT NAME='pin3' VALUE='' SIZE='15' MAXLENGTH='15'>");  
         client.println("<INPUT TYPE=SUBMIT NAME='submit' VALUE='Enter Unlock PIN'>");
         client.println("</form>");       
         client.println("</td>");
         
         client.print("<td>");
         client.println("<span class=\"label label-danger\">");
         client.print(w3);
         client.println("</span>");
         client.print("</td>");
          client.println("</tr>");

          client.println("<tr class=\"success\">");
          client.println("<td color=blue>");
          client.print("104 &nbsp;&nbsp;&nbsp;&nbsp;");
          client.println("</td>");
          
          client.println("<td>");
          client.print("<strong>");
          client.print(result4);
          client.print("</strong>");
          client.println("</td>");
          
          
          client.println("<td>");       
         if(Row4==1)
         {
              client.print(myRand[3]);
              Row4++;
          }
          client.println("</td>");
          
         client.println("<td>");
         client.println("<form action='/' method=get>");
         client.print("<INPUT TYPE=TEXT NAME='pin4' VALUE='' SIZE='15' MAXLENGTH='15'>");  
         client.println("<INPUT TYPE=SUBMIT NAME='submit' VALUE='Enter Unlock PIN'>");
         client.println("</form>");          
         client.println("</td>");

         client.print("<td>");
         client.println("<span class=\"label label-danger\">");
         client.print(w4);
         client.println("</span>");
         client.print("</td>");
          client.println("</tr>");
          client.println("</table>");
          ////////////
          
          client.println("<br />");
          client.println("<br />");
          
          client.println("<p>&nbsp;</p>");
          client.println("<p>&nbsp;</p>");
          client.println("<p>&nbsp;</p>");
          client.println("<p>&nbsp;</p>");
         
          client.println("<footer class=\"container-fluid success\">");
          client.println("<strong> Created By Shibly And Mashuk </strong>");
          client.println("</footer>");

          
          client.println("</center>");
          client.println("</BODY>");
          client.println("</HTML>");

          delay(1);
          //stopping client
          client.stop();
          //controls the Arduino if you press the buttons

        }
      }
    }
  }
}

