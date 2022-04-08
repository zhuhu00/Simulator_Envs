#!/usr/bin/env python

"""
Subscribes to gps topic
"""

import rospy
import roslib
from nav_msgs.msg import Path
from sensor_msgs.msg import NavSatFix
roslib.load_manifest("rover_drivers")


class GpsSub:
    def __init__(self):
        rospy.init_node("gps_sub")
        rospy.on_shutdown(self.on_shutdown)
        print "Starting gps subscriber"

        self.sub = rospy.Subscriber('fake_gps', NavSatFix, self.gps_callback)

    def gps_callback(self, gps):
        lat = gps.latitude
        lon = gps.longitude
        print lat, lon

    def on_shutdown(self):
        pass


if __name__ == '__main__':
    try:
        gps_sub = GpsSub()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass