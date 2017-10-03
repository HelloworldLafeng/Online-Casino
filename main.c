#include <stdio.h>
#include<string.h>
#include <stdlib.h>

#define maxn 5
int main() {
    char roll[maxn];                           //创建一个数组用于记录用户输入字符
    int flag=0;                                //立下一个flag，一会用于判断是否需要重新输入输出
    printf("澳门首家线上赌场开业啦！\n""x志浩在线发牌！\n");                        //x志浩mdzz
    do{
        scanf("%s",roll);
        flag=1;
        if(strlen(roll)!=1);                    //输入的并非单字符，你是来捣乱的，滚蛋吧
        else if(strlen(roll)==1){
            if(roll[0]=='y')printf("OK\n");
            else if(roll[0]=='n')printf("Not Bad\n");
            else {                                       //你是不是不懂规则，为什么不输入y||n，再给你一次机会
                printf("请您吃点药，输入正确的数据\n");
                flag=0;
            }
        }
    }while(flag==0);
    system("pause");
    return 0;
}