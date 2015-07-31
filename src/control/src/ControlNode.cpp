/**
 * @file ControlNode.cpp
 * @author Matt Anderson <mia2n4>
 * @brief The implementation file for the ControlNode class
*/

#include "ControlNode.h"

void ControlNode::joy_callback(const sensor_msgs::Joy::ConstPtr& msg)
{

}

ControlNode::ControlNode()
{
	joy_sub = nh.subscribe<sensor_msgs::Joy>("joy", 1, 
	                                         &ControlNode::joy_callback, this);
}
