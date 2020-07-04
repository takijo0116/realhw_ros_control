#include <ros/ros.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <map>
#include <string>
#include <vector>
#include <std_msgs/Int32.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32MultiArray.h>

class TRobo : public hardware_interface::RobotHW
{
public:
  TRobo();

  ros::NodeHandle nh;

  ros::Time getTime() const { return ros::Time::now(); }
  ros::Duration getPeriod() const { return ros::Duration(0.01); } //0.01sで

  void timeCallback(const std_msgs::Float32::ConstPtr& msg_sub);


  ros::Publisher pub;
  ros::Subscriber sub;

  void read(ros::Time, ros::Duration);

  void write(ros::Time, ros::Duration);
  //void write(ros::Time, ros::Duration,std_msgs::Float32 msg_pub);


protected:
  hardware_interface::JointStateInterface jnt_state_interface;
  hardware_interface::PositionJointInterface jnt_pos_interface;
  double cmd_[1];
  double pos_[1];
  double vel_[1];
  double eff_[1];

};

