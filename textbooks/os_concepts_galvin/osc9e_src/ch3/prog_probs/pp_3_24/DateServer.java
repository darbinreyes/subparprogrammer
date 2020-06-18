import java.net.*;
import java.io.*;

public class DateServer
{
  public static void main(String[] args) {
    String haiku = "fu-ru-i-ke ya\n"
                   + "ka-wa-zu to-bi-ko-mu\n"
                   + "mi-zu-no-o-to";
    try {
      ServerSocket sock = new ServerSocket(5575);

      /* now listen for connections */
      while (true) {
        Socket client = sock.accept();

        PrintWriter pout = new PrintWriter(client.getOutputStream(), true);

          /* write the Date to the socket */
        pout.println(new java.util.Date().toString());

        /* close the socket and resume */
        /* listening for connections */
        client.close();
      }
    }
    catch (IOException ioe) {
      System.err.println(ioe);
    }
  }
}