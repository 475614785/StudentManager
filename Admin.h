#ifndef ADMIN_H
#define ADMIN_H
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

#endif