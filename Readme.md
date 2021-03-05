# README:



## <u>About</u>

This project is meant to be an interactive generative wallpaper communicating with a wireless esp32-based weather station which on its server, allows client machines to read temperature, humidity, and light level values from it. The wallpaper itself (all of it which is procedurally generated) the weather and art itself on the wallpaper changes based on the values it retrieves from the esp32 weather station. 

Demo of the Generative art:

Demo of the entire system: 



## <u>Installation/Setup</u>

### Program Installations

1. Clone this github repo

   ```
   git clone https://github.com/bnhwa/esp32Wifi.git
   ```

   

2. Download Processing [here](https://processing.org/download/).

3. Arduino needs to be installed. Go [here](https://www.arduino.cc/en/software) to download the latest version. Open the Arduino IDE and follow the instructions [here](https://randomnerdtutorials.com/getting-started-with-esp32/) to configure Arduino for the ESP32 and download the ESP32 board configuration. Once this is done, select board "ESP32 Wrover module." Once this is done, download the following libraries:

   [DHT-sensor library](https://github.com/adafruit/DHT-sensor-library/archive/master.zip)

   [ESP-32 Async library](https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip)

   [Async TCP library](https://github.com/me-no-dev/AsyncTCP/archive/master.zip)

4. After downloading these libraries in .zip form, go in the Arduino IDE and go to `Sketch->Include Library->Add .zip Library`  and select all 3 of the above libraries that you just downloaded.


### Hardware Setup 

1. The hardware comprises of the following:

   1 esp32,

   1 DHT11 temperture/hygrometer

   1 Photoresistor

   2 10k resistors

   1 3.7 650 mA rechargeable battery

2. Connect the controller USB to the ESP32 unit

3. Open the Arduino IDE, upload `Weather_server.ino` esp32 board

4. Once you successfully upload to the esp32 unit, a local wifi network (set up by defaut as ESP32-Access-Point") will appear. 

5. On the client machine, connect to that and enter the password (set default as 123456789) 

6. To test if the server is working, go to a web browser to `http://192.168.4.1/dat` and it should return a page with the string of the temperature, humidity, and raw light level

   

## <u>Running</u> (on any computer)

1. Connect the controller USB to the ESP32 unit
2. Open the Arduino IDE, upload `Weather_server.ino` esp32 board
3. Once you successfully upload to the esp32 unit, a local wifi network (set up by defaut as ESP32-Access-Point") will appear. 
4.  On the client machine, connect to that and enter the password (set default as 123456789) 
5. To test if the server is working, go to a web browser to `http://192.168.4.1/dat` and it should return a page with the string of the temperature, humidity, and raw light level
6. Then, once the server is running, while connected to the esp32 wifi network, run `generative_weather.pde`. voila!

