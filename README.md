#Sun-Seeker
A single-axis sun seeking solar panel, aimed to extract maximum efficiency from the solar panel by tracking the sun and uses an IoT platform (Blynk) to display readings of voltage, current and power.

Description:
It uses a sg90 servo motor, which has a range of 0-180 degrees and 2 Light Dependent Resistors (LDRS). If light is incident on a LDR, its resistance reduces. The servo motor turns in the direction of the LDR that outputs the least resistance out of the existing 2 LDRs.
Using the built-in Wi-Fi function of the ESP32 and Blynk libraries, the app can be set up to display the readings of voltage current and power, by getting the values from the voltage and current sensors, connected to the output of the panel.

(*THE VALUES OF POSITIONAL CHANGE AND LDR THRESHOLD ARE SET PURELY FOR DEMONSTRATION PURPOSES. FOR PRACTICAL APPLICATION, APPROPRIATE VALUES SHOULD BE USED TO ENSURE OPTIMAL FUNCTIONING)
