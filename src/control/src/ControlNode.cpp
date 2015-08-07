/**
 * @file ControlNode.cpp
 * @author Matt Anderson <mia2n4>
 * @brief The implementation file for the ControlNode class
*/

#include "ControlNode.h"

void ControlNode::joy_callback(const sensor_msgs::Joy::ConstPtr& msg)
{
    cmd_vel.linear.x = msg->axes[1];
    cmd_vel.angular.y = msg->axes[2];
}

ControlNode::ControlNode()
{
	cmd_vel.linear.x = 0;
	cmd_vel.linear.y = 0;
	cmd_vel.linear.z = 0;
	cmd_vel.angular.x = 0;
	cmd_vel.angular.y = 0;
	cmd_vel.angular.z = 0;

	joy_sub = nh.subscribe<sensor_msgs::Joy>("joy", 1, 
	                                         &ControlNode::joy_callback, this);

	cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);
}

void ControlNode::update()
{
	cmd_vel_pub.publish(cmd_vel);
}
