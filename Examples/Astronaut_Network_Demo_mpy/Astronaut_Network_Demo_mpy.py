import network
import urequests
import time
import neopixel
import machine

# Set up the NeoPixel LED
pin = machine.Pin("NEOPIXEL")
led = neopixel.NeoPixel(pin, 1)

# Set the LED to red while connecting to WiFi
led[0] = (255, 0, 0)
led.write()

# Connect to a WiFi network
wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect('WIFI_NETWORK', 'WIFI_PASSWORD')

# Wait for the connection to complete
print("Waiting for connection...")
while not wlan.isconnected():
    time.sleep(1)
    print('.', sep='', end='', )
print('Connected!')

# Set the LED to blue while downloading data
led[0] = (0, 0, 255)
led.write()

# Download the list of astronauts currently in space
print('Downloading list of astronauts currently in space...')
astronauts = urequests.get("https://corquaid.github.io/international-space-station-APIs/JSON/people-in-space.json").json()

# Print the number of astronauts and their names
number = astronauts['number']
print('There are', number, 'astronauts in space.')
for i in range(number):
    print(i+1, astronauts['people'][i]['name'])

# Set the LED to green to indicate success
led[0] = (0, 255, 0)
led.write()
