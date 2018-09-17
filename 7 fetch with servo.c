// Created on Thu Nov 30 2017

int main() {
	create_connect();
	
	// spin until you see a big enough red blob
	while(track_size(0, 0) < 30) {
		track_update();
		create_spin_CCW(120);
		sleep(0.1);
	}
	
	// drive towards blob until center reaches y-coordinate 98	
	while(track_y(0,0) < 98) {
		// update camera info
		track_update();
		create_drive_direct(250+80-track_x(0,0), 250+track_x(0,0)-80);
		sleep(0.1);
	}
	
	// stop motors
	create_stop();
	printf("Arrived at object.");
	
	// pick up the object
	int servo_position = 1024;
	while (servo_position > 330) {
		servo_position = servo_position - 10;
		set_servo_position(0, servo_position);
	}
	sleep(4);
	
	// after the object is picked up, find a big enough blue blob
	while(track_size(3, 0) < 60) {
		track_update();
		create_spin_CCW(120);
		sleep(0.1);
	}
	
	// drive to blue return blob and stop
	while(track_y(3,0) < 70) {
		// update camera info
		track_update();
		create_drive_direct(250+80-track_x(3,0), 250+track_x(3,0)-80);
		sleep(0.1);
	}
	
	create_stop();
	
	// drop object
	while (servo_position < 1000) {
		servo_position = servo_position + 10;
		set_servo_position(0, servo_position);
	}
	set_servo_position(0, 1024);
	
	printf("Returned object.");	
	create_disconnect();
}
