# TTGO T DISPLAY Example
Sort of Hello World for the "TTGO T Display" ESP32 board. This example uses the arduino framework and is made with Platform.io.

The code in `main.cpp` connects to your Wifi, setups NTP to get the date and time, and then prints it on the board display.

## How To

- Install vscode with Platform.io https://platformio.org/install/ide?install=vscode
- Clone this repo and open the folder with vscode
- Copy `credentials.h.dist` to `credentials.h` and replace the ssid and password
- Plug the board in
- Click build in the tool bar https://docs.platformio.org/en/latest/integration/ide/vscode.html#platformio-toolbar
- Finally click upload and open the serial monitor to read the debug logs
