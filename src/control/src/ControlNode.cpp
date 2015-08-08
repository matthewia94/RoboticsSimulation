/**
 * @file ControlNode.cpp
 * @author Matt Anderson <mia2n4>
 * @brief The implementation file for the ControlNode class
*/

#include "ControlNode.h"

void ControlNode::joy_callback(const sensor_msgs::Joy::ConstPtr& msg)
{
	//Check for a mode change
    if(msg->buttons[B_BUTTON] == 1)
    	mode = STANDBY;
    else if(msg->buttons[A_BUTTON])
    	mode = TELEOP;
    else if(msg->buttons[Y_BUTTON])
    	mode = AUTO;

    if(mode == TELEOP)
    {
    	cmd_vel.linear.x = msg->axes[1];
		cmd_vel.angular.y = msg->axes[2];
    }
}

void ControlNode::stop_robot()
{
	cmd_vel.linear.x = 0;
	cmd_vel.linear.y = 0;
	cmd_vel.linear.z = 0;
	cmd_vel.angular.x = 0;
	cmd_vel.angular.y = 0;
	cmd_vel.angular.z = 0;
}

ControlNode::ControlNode()
{
	mode = STANDBY;
	stop_robot();

	joy_sub = nh.subscribe<sensor_msgs::Joy>("joy", 1, 
	                                         &ControlNode::joy_callback, this);

	cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);
}

void ControlNode::update()
{
	switch(mode)
	{
		case STANDBY:
			stop_robot();
			break;
		case TELEOP:
			//Telop stuff here
			break;
		case AUTO:
			//Autonomous stuff here
			break;
		default:
			stop_robot();
	}
	cmd_vel_pub.publish(cmd_vel);
}
