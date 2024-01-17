#include"student.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//注册(学生)功能函数
void zhuce_student(Students students,char name[],int id,char password1[],char password2[]){
    //1、判断密码是否不一致
    if(strcmp(password1,password2)!=0){
        printf("两次密码不一致\n");
        return;
    }
    //2、定位末尾并且判断学号是否重复
    while(students->next!=NULL){
        if(students->next->id==id){
            printf("学号重复\n");
            return;
        }
        students=students->next;
    }
    //2、创建学员
    Student * newStudent =  create_StudentNode(name,id,password1);
    //3、指针域赋值
    students->next=newStudent;
    //保存文件，追加
    /*
    FILE *file=NULL;
    char filename[]="student.txt";
    file= fopen(filename,"a");
    if(file==NULL){
        printf("追加失败%s\n", filename);
        return ;
    }
    fprintf(file,"姓名%s\n学号%d\n密码%s\n",newStudent->name,newStudent->id,newStudent->password);
    fclose(file);
    printf("注册成功\n");
    */
    print_txt();
    return;
};

//超管登陆账号密码匹配函数(管理员登录)
void administrators_login(char id[],char password[],int *count){
    if(count<=5){
        if(strcmp(id,"admin")!=0){
            printf("账户不存在\n");
            (*count)++;
            return;
        }
        if(strcmp(password,"admin")!=0){
            printf("密码错误\n");
            (*count)++;
            return;
        }else{
            *count=0;
            //进入管理系统
            
        }
    
    }else{
        printf("错误次数过多\n");
        return;
    }
    return;
};
//管理员登陆账号密码匹配函数(管理员登录)
void admin_login(Admin admins,char id[],char password[],int *count){
        if(count>5){
            printf("错误次数过多\n");
            return;
        }
        //定位到需要修改的学生
        AdminList admin = admins->next;
        while(admin!=NULL){
            //满足条件
            if(strcmp(admin->id,id)==0){
                break;
            }
            admin = admin->next;
        }
        if(admin==NULL ){
            printf("账户不存在\n");
            (*count)++;
            return;
        }
        if(strcmp(admin->password,password)==0){
            // 登录成功,进入界面
            *count=0;
            admin_part();
        }else{
            printf("密码错误\n");
            (*count)++;
            return ;
        }
    return;
};
//学生登录账号密码匹配(学生登录 ) 
void student_login(Students students,char id[],char password[],int *count){
        if(count>5){
            printf("错误次数过多\n");
            return;
        }
        //查询学生学号
        Students student = students->next;
        while(student!=NULL){
            //满足条件
            if(strcmp(student->id,id)==0){
                break;
            }
            student = student->next;
        }
        if(student==NULL ){
            printf("学生学号不存在\n");
            (*count)++;
            return;
        }
        // 匹配密码
        if(strcmp(student->password,password)==0){
            // 登录成功,进入界面
            *count=0;
            student_part();
        }else{
            printf("密码错误\n");
            (*count)++;
            return ;
        }
    return;
};