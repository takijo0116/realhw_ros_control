#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <realhw_control/realhw.h>

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "trobo");
  
  TRobo trobo;
  controller_manager::ControllerManager cm(&trobo, trobo.nh);

  ros::Rate rate(1 / trobo.getPeriod().toSec());
  ros::AsyncSpinner spinner(1);
  spinner.start();

  while(ros::ok())
  {
    ros::Time now = trobo.getTime();
    ros::Duration dt = trobo.getPeriod();

    trobo.read(now, dt);
    cm.update(now, dt);
    trobo.write(now, dt);
    rate.sleep();
  }
  spinner.stop();

  return 0;
}

