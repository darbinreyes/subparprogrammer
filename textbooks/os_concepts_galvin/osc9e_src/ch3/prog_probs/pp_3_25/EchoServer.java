import java.net.*;
import java.io.*;

public class EchoServer
{
  public static void main(String[] args) {
    try {
      ServerSocket sock = new ServerSocket(6013);

      /* now listen for connections */
      while (true) {
        Socket client = sock.accept();

        /* Read what the client sent us */
        InputStream in = client.getInputStream();
        BufferedReader bin = new BufferedReader(new InputStreamReader(in));
        String line;
        while ( (line = bin.readLine()) != null)
          System.out.println(line);
        /*  ******* */
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