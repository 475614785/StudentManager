#ifndef STUDENT_H
#define STUDENT_H
//学生信息定义
typedef struct Student{
    char name[20];
    int id;
    char password[20];
    int classNumber;
    int score_math;
    int score_chinese;
    int score_english;
    int age;
    struct Student* next; 
}Student,*Students;

//超级管理员
typedef struct Administrators{
    char id[20];
    char password[20];
}Administrators;
  
//管理员定义
typedef struct Admin{
    char id[20];
    char password[20];
    int classNumber;
    struct Admin* next; 
}Admin,*AdminList;


//管理员添加
//管理员删除
//管理员修改
//管理员查询
//读取文件
//保存文件

//学生删除
//学生修改
//学生查询
//学生排序
//欢迎界面


//管理员功能
//录入学生信息
void inpu_student();
// 显示全部学生
void print_all();
//按姓名查询
void print_byname();
// 按学号查询
void print_byid();
// 修改学生成绩
void updata_grade();
//根据成绩排列
void paixu_bygrade();
//根据学号排列
void paixu_byid();
//将所有学生信息输出到txt文档
void print_txt();

//学生功能
//查询自己信息
void print_my();
//修改自己密码
void updata_password();


//注册(学生)功能函数
void zhuce_student();

//超管登陆账号密码匹配函数(管理员登录)
void administrators_login();
//管理员登陆账号密码匹配函数(管理员登录)
void admin_login();
//学生登录账号密码匹配(学生登录 ) 
void student_login();

//查看个人信息
//修改密码

#endif