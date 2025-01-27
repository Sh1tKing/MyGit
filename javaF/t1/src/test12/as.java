package test12;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;

import static java.lang.Thread.sleep;

public class as {
    public static void GetData() throws Exception {
        String apiUrl = "https://iot-api.heclouds.com/thingmodel/query-device-property?product_id=4aS7AhlV8X&device_name=circlecheck";
        String authorizationValue = "version=2022-05-01&res=userid%2F390250&et=2016217735&method=sha1&sign=pq%2Bbjtzv8VTEJcqS2v5uIME7uMk%3D";//密钥

        URL url = new URL(apiUrl);
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("GET");

        //Authorization头
        connection.setRequestProperty("Authorization", authorizationValue);
        connection.setRequestProperty("Accept-Language", "en-US,en;q=0.5");

        if (connection.getResponseCode() == HttpURLConnection.HTTP_OK) {
            BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream(), StandardCharsets.UTF_8));
            String inputLine;
            StringBuilder content = new StringBuilder();

            while ((inputLine = in.readLine()) != null) {
                content.append(inputLine); //内容都在content
            }

            in.close();

            System.out.println(content.toString());
        } else {
            System.out.println("error" + connection.getResponseCode());
        }

        connection.disconnect();
    }

    public static void main(String[] args) throws Exception {
        Runnable runnable = new Runnable() {
            public void run() {
                while (true) {
                    try {
                        GetData();
                    } catch (Exception e) {
                        throw new RuntimeException(e);
                    }
                    try {
                        Thread.sleep(1000); //定时1s执行一次
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };
        Thread thread = new Thread(runnable);
        thread.start();
    }
}