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
}card[52];                                        //�������ڵ����ƿ�
void palyingcards(struct feature card[]){
    for(int i=0;i<=3;i++){
        for(int n=1;n<=13;n++){
            card[i*13+n-1].num=n;
            card[i*13+n-1].kin=i;
        }
    }
}                                                 //��ʼ���ƿ⣬�������Ʊ�������JQKAδ���¶���
void shuffle(struct feature a[],int n){
    for(int i=0;i<n;i++){
        int tab=rand()%(n-i)+i;
        struct feature tab1;
        tab1=a[i];
        a[i]=a[tab];
        a[tab]=a[tab1];
    }
}                                                      //ϴ�ƺ�������Ҫ����a[]=card[]�Լ�n=52

int main() {
    char roll[maxn];                           //����һ���������ڼ�¼�û������ַ�
    int flag=0;                                //����һ��flag��һ�������ж��Ƿ���Ҫ�����������
    printf("�����׼����϶ĳ���ҵ����\n""x־�����߷��ƣ�\n");                        //x־��mdzz
    do{
        scanf("%s",roll);
        flag=1;
        if(strlen(roll)!=1){
            printf("�����Ե�ҩ��������ȷ������\n");
            flag=0;
        }                    //����Ĳ��ǵ��ַ�������úô��ڶĳ���Ǯ��⣬��������
        else if(strlen(roll)==1){
            if(roll[0]=='y')printf("OK\n");
            else if(roll[0]=='q')printf("Bye\n");
            else if(roll[0]=='n')printf("Not Bad\n");
            else {                                       //���ǲ��ǲ�������Ϊʲô������y||n���ٸ���һ�λ���
                printf("�����Ե�ҩ��������ȷ������\n");
                flag=0;
            }
        }
    }while(flag==0);
    system("pause");
    return 0;
}