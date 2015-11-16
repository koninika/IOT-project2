gcc -o gateway  Gateway.c -lpthread
gcc -o mo motion.c
gcc -o ko keychain.c
gcc -o do door.c
gcc -o bo backend.c
gnome-terminal -e ./bo
sleep 1;
gnome-terminal -e ./gateway
sleep 2;
gnome-terminal -e ./do #DoorConfigurationFile.txt DoorStateFile.txt
sleep 2;
gnome-terminal -e ./ko #KeychainConfigurationFile.txt KeychainStateFile.txt
sleep 2;
gnome-terminal -e ./mo #MotionSensorConfigurationFile.txt MotionSensorStateFile.txt
#/home/devendralattu/Desktop/AOS/Project2/15Nov/
