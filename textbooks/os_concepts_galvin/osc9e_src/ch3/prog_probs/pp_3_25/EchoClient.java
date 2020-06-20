import java.net.*;
import java.io.*;

public class EchoClient
{
  public static void main(String[] args) {
    try {
      Socket sock = new Socket("127.0.0.1", 6013);

      /* Send something to the server */
      String send_str = "Hello, my name is Dijkstra.";
      OutputStream out = sock.getOutputStream();
      InputStream in = sock.getInputStream();
      int next_byte;

      for (int i = 0; i < send_str.length(); i++){
        out.write(send_str.charAt(i)); // Send a byte
        next_byte = in.read(); // Receive a byte
        System.out.println(new Integer(next_byte)); // Print received byte.
      }

      sock.close();
    }
    catch (IOException ioe) {
      System.err.println(ioe);
    }
  }
}