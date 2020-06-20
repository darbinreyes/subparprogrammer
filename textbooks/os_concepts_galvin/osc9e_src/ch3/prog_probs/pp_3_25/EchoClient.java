import java.net.*;
import java.io.*;

public class EchoClient
{
  public static void main(String[] args) {
    try {
      Socket sock = new Socket("127.0.0.1", 6013);

      /* Send something to the server */
      String send_str = "Hello, my name is Dijkstra"; // FYI: Adding this causes the following exception after client prints date: java.net.SocketException: Connection reset
      PrintWriter pout = new PrintWriter(sock.getOutputStream(), true);
      pout.println(send_str);

      /* ******** */
      InputStream in = sock.getInputStream();
      BufferedReader bin = new BufferedReader(new InputStreamReader(in));

      /* read the date from the socket */
      //String line;
      //while ( (line = bin.readLine()) != null)
        //System.out.println(line);

      /* close the socket connection */
      sock.close();

    }
    catch (IOException ioe) {
      System.err.println(ioe);
    }
  }
}