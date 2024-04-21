#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <iostream>
#include <vector>
using namespace std;

class cl_base
{
	string s_name;
	cl_base* p_head_obj;
	vector<cl_base*> p_sub_objects;
public:
	cl_base(cl_base* p_head_obj, string s_name = "Base Object"); //конструктор
	bool set_name(string s_new_name); //метод редактирования имени
	string get_name(); //метод получения имени объекта
	cl_base* get_head_obj(); //метод получения указателя на головной объект т
	void print_tree(); //метод вывода наименований объектов
	cl_base* get_sub_object(string s_name); //метод получения указателя на непосредственно подчиненный объект по его имени
	~cl_base();
};

#endif
