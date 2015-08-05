/**
 * @file control_node.cpp
 * @author Matt Anderson <mia2n4>
 * @brief The control node file
*/

#include "ControlNode.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "control");

	ControlNode con;

	ros::Rate loop_rate(30);

	while(ros::ok())
	{
		con.update();
		ros::spinOnce();
	}
}
