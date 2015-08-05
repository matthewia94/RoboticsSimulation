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

class ControlNode
{
	private:
	    geometry_msgs::Twist cmd_vel;
	
		ros::NodeHandle nh;

		//Publishers
		ros::Publisher cmd_vel_pub;

		//Subscribers
		ros::Subscriber joy_sub;

	public:
		ControlNode();
		
		void joy_callback(const sensor_msgs::Joy::ConstPtr& msg);

		void update();

};

#endif
