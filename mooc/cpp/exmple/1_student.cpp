#include<iostream>
#include<cstring>
using namespace std;

class info{
	int Id;
	char Name[20];
	int Programming;
	int Network;
	int Database;
	int Total;
public:
	void set_info(int id,char *name,int programming,int network,int database);
	int get_pro();
	int get_net();
	int get_dat();
	int get_tol();
	void show();
};
void info::set_info(int id,char *name,int programming,int network,int database)
{
	Id = id;
	strcpy(Name,name);
	Programming = programming;
	Network = network;
	Database = database;
	Total = programming + network + database;
}
int info::get_pro()
{
	return Programming;
}
int info::get_net()
{
	return Network;
}
int info::get_dat()
{
	return Database;
}
int info::get_tol()
{
	return Total;
}
void info::show()
{
	cout<<Id<<"\t";
	cout<<Name<<"\t";
	cout<<Programming<<"\t";
	cout<<Network<<"\t";
	cout<<Database<<"\t";
	cout<<Total<<endl;
}

int main(void)
{
	const int MAX_COUNT = 100;
	int count;
	int i = 0,j = 0;
	int id,programming,network,database;
	char name[20];
	info student[MAX_COUNT],tmp;

	cout<<"清输入学生人数： ";
	cin>>count;
	while(count > MAX_COUNT){
		cout<<"学生人数不能超过"<<MAX_COUNT<<"人，请重新输入： ";
		cin>>count;
	}
	cout<<"请输入学生成绩的信息"<<endl;
	cout<<"学号 姓名 程序设计 计算机网络 数据库"<<endl;

	for(i=0;i<count;i++){
		cin>>id>>name>>programming>>network>>database;
		student[i].set_info(id,name,programming,network,database);
	}
	cout<<"按总分高低排名如下： "<<endl;
	for(i=0;i<count;i++)
		for(j=count-1;j>i;j--)
			if(student[j].get_tol() > student[j-1].get_tol()){
				tmp = student[j];
				student[j] = student[j-1];
				student[j-1] = tmp;
			}
	cout<<"学号 姓名 程序设计 计算机网络 数据库 总分"<<endl;
	for(i=0;i<count;i++)
		student[i].show();
	cout<<"每门课程成绩大于85分的学生名单： "<<endl;
	cout<<"学号 姓名 程序设计 计算机网络 数据库 总分"<<endl;
	for(i=0;i<count;i++)
		if(student[i].get_pro()>85 && student[i].get_net()>85 && student[i].get_dat()>85)
			student[i].show();

	return 0;
}
