import rclpy
from rclpy.node import Node

from tyrant_interfaces.msg import VehicleState


class StatePublisher(Node):
    def __init__(self):
        super().__init__("state_publisher")

        self.publisher = self.create_publisher(
            VehicleState,
            "/tyrant/state",
            10,
        )

        self.timer = self.create_timer(
            0.1,
            self.publish_state,
        )

        self.counter = 0

        self.get_logger().info(
            "Tyrant VehicleState publisher started"
        )

    def publish_state(self):
        msg = VehicleState()

        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "odom"

        msg.position.x = float(self.counter) * 0.01
        msg.position.y = 0.0
        msg.position.z = -1.0

        msg.linear_velocity.x = 0.1
        msg.linear_velocity.y = 0.0
        msg.linear_velocity.z = 0.0

        msg.angular_velocity.x = 0.0
        msg.angular_velocity.y = 0.0
        msg.angular_velocity.z = 0.0

        msg.roll = 0.0
        msg.pitch = 0.0
        msg.yaw = 0.0

        msg.estimator_status = 1

        self.publisher.publish(msg)
        self.counter += 1


def main(args=None):
    rclpy.init(args=args)

    node = StatePublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()