# Vehicle_Simulator

Motor Class:
A motor class(motor.h) was designed to handle the motion of DC and stepper motors. This class encapsulated data and functions related to motor control, including constructors and destructors. The design ensured appropriate access control for data and functions.

Robot and Car Classes: The project included the implementation of robot class(robot.h) for both robot and car instances, which utilized the motor class for motion control. These classes inherited certain data and functions from a vehicle class. The design involved defining data structures, member functions, constructors, and destructors, with careful consideration of access modifiers for encapsulation.

Configuration File Handling: The software prompted the user to specify a configuration filename containing essential parameters such as vehicle type, motor specifications, wheel radius, track width, and wheelbase in a CSV format. The IOFile class was utilized to read the configuration file, ensuring accurate parameter retrieval for simulation setup.

IOFile Class: An IOFile class was developed to facilitate reading and writing comma-separated values (CSV) files. This class provided functionalities for file input/output operations, including constructors and destructors. Access modifiers were chosen to ensure proper encapsulation and data protection.

Vehicle Movement Simulation: Using parameters from the configuration file, the software simulated the movement of the vehicle from a starting position (5, 5) to a target position (5, 25) in meters. The vehicle's initial orientation was set to 0 degrees. The simulation involved rotating the vehicle towards the target position and then moving straight towards it, adhering to the differential drive model for the mobile robot and the bicycle model for the autonomous bicycle.

Pose Logging: During the simulation, the software logged the position (x, y) and orientation of the vehicle at each iteration into a CSV file using the IOFile class. Each line in the CSV file contained the vehicle's position and orientation data for analysis and visualization purposes.

Visualization process done using MATLAB.
