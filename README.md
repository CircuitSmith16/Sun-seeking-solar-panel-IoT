#Sun-Seeker
A single-axis sun seeking solar panel, aimed to extract maximum efficiency from the solar panel by tracking the sun and uses an IoT platform (Blynk) to display readings of voltage, current and power.

Description:
It uses a sg90 servo motor, which has a range of 0-180 degrees and 2 Light Dependent Resistors (LDRS). If light is incident on a LDR, its resistance reduces. The servo motor turns in the direction of the LDR that outputs the least resistance out of the existing 2 LDRs.
Using the built-in Wi-Fi function of the ESP32 and Blynk libraries, the app can be set up to display the readings of voltage current and power, by getting the values from the voltage and current sensors, connected to the output of the panel.

Technical details:
1. Servo motor - 5V DC, offers 180 degree rotation which is perfect for this case, as we do not require angles of high values.
2. Solar Panel - 5V DC, a project level solar panel was used here.
3. ESP32 Dev module - The brain of the system where we integrated the blynk platform to view real-time production status.
4. ACS712 current sensor - a hall effect sensor measures both AC and DC.
5. Voltage sensor - works based on voltage division.

Expanding it to real life systems:
In real life, solar panel setups of several kilowatts are set up, which handles high voltage and produces high power. Connecting such DC devices directly would instantly fry them.
An inverter is connected to the solar panel setup, so as to facilitate power delivery based on whether it is an on-grid or an off-grid system.
the microcontroller can obtain values from the inverter and using our programming logic, data can be sent to a mobile phone to view analytics

(*THE VALUES OF POSITIONAL CHANGE AND LDR THRESHOLD ARE SET PURELY FOR DEMONSTRATION PURPOSES. FOR PRACTICAL APPLICATION, APPROPRIATE VALUES SHOULD BE USED TO ENSURE OPTIMAL FUNCTIONING)
