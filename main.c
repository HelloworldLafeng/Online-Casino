#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#define maxn 5
enum number{A=1,J=10,Q=10,K=10,UN=11};
enum kind{fangpian,hongtao,meihua,heitao};
struct feature{
    enum number num;
    enum kind kin;
}card[52];                                        //数组用于当作牌库
void palyingcards(struct feature card[]){
    for(int i=0;i<=3;i++){
        for(int n=1;n<=13;n++){
            card[i*13+n-1].num=n;
            card[i*13+n-1].kin=i;
        }
    }
}                                                 //初始化牌库，将所有牌编满，且JQKA未重新定义
void shuffle(struct feature a[],int n){
    for(int i=0;i<n;i++){
        int tab=rand()%(n-i)+i;
        struct feature tab1;
        tab1=a[i];
        a[i]=a[tab];
        a[tab]=a[tab1];
    }
}                                                      //洗牌函数，需要变量a[]=card[]以及n=52

int main() {
    char roll[maxn];                           //创建一个数组用于记录用户输入字符
    int flag=0;                                //立下一个flag，一会用于判断是否需要重新输入输出
    printf("澳门首家线上赌场开业啦！\n""x志浩在线发牌！\n");                        //x志浩mdzz
    do{
        scanf("%s",roll);
        flag=1;
        if(strlen(roll)!=1){
            printf("请您吃点药，输入正确的数据\n");
            flag=0;
        }                    //输入的并非单字符，请你好好呆在赌场把钱输光，重新输入
        else if(strlen(roll)==1){
            if(roll[0]=='y')printf("OK\n");
            else if(roll[0]=='q')printf("Bye\n");
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