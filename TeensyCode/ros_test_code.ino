#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>

// ROS node handle
ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[8] = "cmd vel";


// Constants for maximum velocities
const float MAX_VELOCITY_X = 10.0;  // Adjust as needed
const float MAX_VELOCITY_Y = 10.0;  // Adjust as needed
const float MAX_ANGULAR_VELOCITY_Z = 5.0;  // Adjust as needed

// Motor direction flags
const bool MOTOR_X1_REVERSE = false;  // Adjust based on your motor configuration
const bool MOTOR_X2_REVERSE = false;  // Adjust based on your motor configuration
const bool MOTOR_Y1_REVERSE = false;  // Adjust based on your motor configuration
const bool MOTOR_Y2_REVERSE = false;  // Adjust based on your motor configuration

// Callback function for cmd_vel messages
void cmdVelCallback(const geometry_msgs::Twist& twistMsg) {
  // Extract linear and angular velocities from the message
  float linearX = twistMsg.linear.x;
  float linearY = twistMsg.linear.y;
  float angularZ = twistMsg.angular.z;

  // Translate cmd_vel values to ODrive velocity commands
  float velX = linearX * MAX_VELOCITY_X;
  float velY = linearY * MAX_VELOCITY_Y;
  float velZ = angularZ * MAX_ANGULAR_VELOCITY_Z;

  // Adjust motor directions for holonomic motion
  float motorX = velX;
  float motorY = velY;

  // Combine velX and velY to achieve desired motion
  motorX += velY;
  motorY += velY;

  if (MOTOR_X1_REVERSE) {
    motorX = -motorX;
  }
  if (MOTOR_X2_REVERSE) {
    motorY = -motorY;
  }
  if (MOTOR_Y1_REVERSE) {
    motorY = -motorY;
  }
  if (MOTOR_Y2_REVERSE) {
    motorX = -motorX;
  }
  digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN)); 

  str_msg.data = hello;
  chatter.publish( &str_msg );

  // Print velocity commands to Serial Monitor
//  Serial.print("velX: ");
//  Serial.print(velX);
//  Serial.print("\t velY: ");
//  Serial.print(velY);
//  Serial.print("\t velZ: ");
//  Serial.println(velZ);
}

void setup() {
  // Start Serial communication for debugging
//  Serial.begin(115200);

  // Initialize ROS
  nh.getHardware()->setBaud(115200);
  nh.initNode();

  // Subscribe to cmd_vel topic
  ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &cmdVelCallback);
  nh.subscribe(sub);
  nh.advertise(chatter);

  // Wait for ODrive to be ready
  delay(2000);

  // Set ODrive parameters as needed
  // odriveX.setParameter(...);
  // odriveY.setParameter(...);
}

void loop() {
  // Handle ROS communication
  nh.spinOnce();
  delay(1);
}