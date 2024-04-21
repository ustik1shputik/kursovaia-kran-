#include "cl_base.h"

cl_base:: cl_base(cl_base* p_head_obj, string s_name)
{
	/*
	Описание: параметризированный конструктор.
	Параметры:
		p_head_obj - указатель на головной объект
		s_name - имя узла дерева
	*/
	
	this -> s_name = s_name; //полю присваиваем параметр
	this -> p_head_obj = p_head_obj;
	
	if (p_head_obj != nullptr)
		p_head_obj -> p_sub_objects.push_back(this); //обращение к полю
}

bool cl_base::set_name(string s_new_name)
{
	/*
	Описание: метод редактирования имени объекта
	Параметры:
		s_new_name - новое имя  узла дерева
	*/
	
	if (this -> p_head_obj)
		for (int i = 0; i < p_head_obj ->  p_sub_objects.size(); i++)
			if (p_head_obj ->  p_sub_objects[i] -> get_name() == s_new_name)
				return false;
		
	this -> s_name = s_new_name;
	return true;
}

cl_base:: ~cl_base()
{
	/*
	Описание: деструктор
	Параметры:
	*/
	
	for(int i = 0; i < p_sub_objects.size(); i++)
		delete p_sub_objects[i];
}

cl_base* cl_base::get_sub_object(string s_name)
{
	/*
	Описание: получение указателя на непосредственно подчиненный объект по имени.
	Параметры:
		s_name - имя искомого объекта
	*/	
	for(int i = 0; i < p_sub_objects.size(); i++)
		if(p_sub_objects[i]->get_name() == s_name)
			return p_sub_objects[i];
	
	return nullptr;
}

void cl_base::print_tree()
{
	/*
	Описание: вывод дерева иерархии
	Параметры:
	*/
	if (p_sub_objects.size() != 0)
	{
		cout << endl << this->get_name();
		for(int i = 0; i < p_sub_objects.size(); i++)
			cout << "  " << p_sub_objects[i] -> get_name();
	}
	
}

string cl_base::get_name()
{
	/*
	Описание: Получение имени объекта 
	Параметры:
	*/
	return s_name;
}

cl_base* cl_base::get_head_obj()
{
	/*
	Описание: Получение имени объекта 
	Параметры:
	*/
	return p_head_obj;
}
