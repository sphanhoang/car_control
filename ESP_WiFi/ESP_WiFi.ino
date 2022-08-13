
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>


// Setup custom serial mySerial at pin D1 and D2
SoftwareSerial mySerial(D1, D2); // (RX, TX)

// WiFi parameters
const char* ssid = "salt2g";            // WiFi's name
const char* password = "68686668";   // and password

String header;

// Initiate server at port 80
WiFiServer server(80);

void setup(void)
{
  // Initiate serial ports
  mySerial.begin(9600);
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  // print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
  server.begin();

}
void loop()
{
  WiFiClient client = server.available();
  if (client)
  {
    Serial.println("New client connected");
    String currentLine = "";
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n')
        {
          if (currentLine.length() == 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            if (header.indexOf("GET /1/") >= 0)
            {
              mySerial.println("1");
            }
            else if (header.indexOf("GET /2/") >= 0)
            {
              mySerial.println("2");
            }

            else if (header.indexOf("GET /3/") >= 0)
            {
              mySerial.println("3");
            }
            else if (header.indexOf("GET /4/") >= 0)
            {
              mySerial.println("4");
            }

            else if (header.indexOf("GET /5/") >= 0)
            {
              mySerial.println("5");
            }
            // Display the HTML web:
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewpoint\" content=\"width=device-width, initial-scale=1\">");
            // CSS styled buttons
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");

            // Webpage heading
            client.println("<body><h1>Webpage Controlled Car</h1>");

            // Display buttons:
            client.println("<p><a href=\"/1/\"><button class=\"button\">Forward</button></a></p>");
            client.println("<p><a href=\"/2/\"><button class=\"button\">Backward</button></a></p>");
            client.println("<p><a href=\"/3/\"><button class=\"button\">Left</button></a></p>");
            client.println("<p><a href=\"/4/\"><button class=\"button\">Right</button></a></p>");
            client.println("<p><a href=\"/5/\"><button class=\"button\">Stop</button></a></p>");
            client.println("</body></html>");

            // HTTP ends with another blank line
            client.println();
            // Break out of the while loop
             break;
          }
            else
          {
            currentLine = "";
          }
        }
        else if (c != '\r')
        {
          currentLine += c;
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
    Serial.println("");
  }
}
