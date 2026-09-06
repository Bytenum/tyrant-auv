import rclpy
from rclpy.node import Node

from tyrant_interfaces.msg import VehicleReference


class ReferenceSubscriber(Node):
    def __init__(self):
        super().__init__("reference_subscriber")

        self.subscription = self.create_subscription(
            VehicleReference,
            "/tyrant/reference",
            self.reference_callback,
            10,
        )

        self.get_logger().info(
            "Tyrant VehicleReference subscriber started"
        )

    def reference_callback(self, msg: VehicleReference):
        self.get_logger().info(
            f"Reference received: "
            f"x={msg.position.x:.2f}, "
            f"y={msg.position.y:.2f}, "
            f"z={msg.position.z:.2f}, "
            f"yaw={msg.yaw:.2f}"
        )


def main(args=None):
    rclpy.init(args=args)

    node = ReferenceSubscriber()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
