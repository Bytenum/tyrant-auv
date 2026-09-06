from setuptools import find_packages, setup

package_name = 'tyrant_monitoring'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='codespace',
    maintainer_email='charistobrillian710@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            "state_publisher = tyrant_monitoring.state_publisher:main",
            "reference_subscriber = tyrant_monitoring.reference_subscriber:main",
        ],
    },
)
