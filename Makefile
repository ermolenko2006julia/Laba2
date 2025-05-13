all:
	g++ DatabaseTask.cpp admin_menu.cpp file_manager.cpp student.cpp student_menu.cpp teacher.cpp teacher_menu.cpp -o smeta
	./smeta
clean:
	rm -f smeta
