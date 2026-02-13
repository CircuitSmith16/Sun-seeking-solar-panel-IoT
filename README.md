The sun-seeking solar panel, orients itself towards the direction receiving light with more intensity when compared to the other direction.
It uses 2 Light Dependent Resistors (LDRS) and a servo motor. When incident light falls on an LDR, its resistance decreases. Using this property, the servo motor can be made to turn when the resistance of one of the LDRS drops lower than the other.
When the Left LDR receives more light, its resistance drops and the servo rotates in that direction & vice versa.
The usage of an ESP32 Wi-Fi microcontroller enables Wi-Fi related functions of the board. Using Blynk IoT, the virtual pins for voltage,current and power can be defined. The code is incorporated with the code elements of Blynk app.
A Voltage and a current sensor reads the output of the solar panel. By using Blynk's virtualWrite function, the values of voltage, current and power can be sent to the respective virtual pins, defined earlier.
By installing Blynk's mobile app and setting up the device in blynk, the values can be seen in the mobile platform.
