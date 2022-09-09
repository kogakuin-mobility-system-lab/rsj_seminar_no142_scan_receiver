#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

#include <iostream>

void callback(const sensor_msgs::LaserScan::ConstPtr &msg) {
  std::cout << msg->angle_min << '\n';
  std::cout << msg->angle_max << '\n';
  std::cout << msg->angle_increment << '\n';
  std::cout << msg->ranges[0] << '\n';
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "scan_receiver");
  ros::NodeHandle node;

  ros::Subscriber sub = node.subscribe("scan", 10, callback);

  ros::spin();

  return 0;
}
