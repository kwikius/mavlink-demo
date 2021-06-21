# mavlink_demo

To run the example

  download and unzip the source to your chosen source directory 

  Navigate to the source directory and invoke make

    >$ make

  Once make has run, list the contents of the working directory. There should be a mavlink_demo.exe application listed.
   
  To try the application, first connect your Ardupilot to your usb port. Wait for it to initialise

  To invoke the application type ( where /dev/ttyACM0 is the serial/usb port)

    >$ ./mavlink_demo.exe /dev/ttyACM0

  The serial port may be different, but if you have no other usb serial type devices connected, then this is a good choice.
  If your ArduPilot uses a FTDI style usart then try /dev/ttyUSB0


  You should see some diagnostic output as the ArduPilot sends mavlink messages:


```
setting baud
input "/dev/ttyACM0" opened ok
heartbeat
sys status
heartbeat
sys status
heartbeat
sys status
heartbeat
sys status

...

```

Press Control-C to terminate the application
