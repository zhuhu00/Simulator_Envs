#!/usr/bin/env python

"""
Publishes a fake gps signal at 1 Hz
"""

import numpy as np
import rospy
import roslib
from nav_msgs.msg import Path
from sensor_msgs.msg import NavSatFix
roslib.load_manifest("rover_drivers")


class FakeGps:
    def __init__(self):
    	rospy.init_node("fake_gps")
        rospy.on_shutdown(self.on_shutdown)
        print "Starting fake gps publisher"

        self.gps_pub = rospy.Publisher('fake_gps', NavSatFix, queue_size=10)

        rospy.Timer(rospy.Duration(1.0 / 1.0), self.publish_gps)

    def publish_gps(self, timerEvent = None):

        # Publish a fake gps coord
        gps = NavSatFix()
        lat = 45.52 + np.random.uniform(low=-0.01, high=0.01)
        lon = -73.52 + np.random.uniform(low=-0.01, high=0.01)
        gps.latitude = lat
        gps.longitude = lon
        self.gps_pub.publish(gps)

    def on_shutdown(self):
        pass


if __name__ == '__main__':
    try:
        fake_gps = FakeGps()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
