/**
 * @file ControlNode.h
 * @author Matt Anderson <mia2n4>
 * @brief The header file for the ControlNode class
*/

#ifndef CONTROL_NODE_H
#define CONTROL_NODE_H

#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>

#define A_BUTTON 0
#define B_BUTTON 1
#define X_BUTTON 2
#define Y_BUTTON 3

class ControlNode
{
	private:
		enum Mode
		{
			STANDBY,
			TELEOP,
			AUTO
		};

		Mode mode;
	    geometry_msgs::Twist cmd_vel;
	    int prev_buttons[14];
	
		ros::NodeHandle nh;

		//Publishers
		ros::Publisher cmd_vel_pub;

		//Subscribers
		ros::Subscriber joy_sub;

		void stop_robot();
	public:
		ControlNode();
		
		void joy_callback(const sensor_msgs::Joy::ConstPtr& msg);

		void update();

};

#endif
