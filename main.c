#include <stdio.h>
#include<string.h>
#include <stdlib.h>

#define maxn 5
int main() {
    char roll[maxn];                           //����һ���������ڼ�¼�û������ַ�
    int flag=0;                                //����һ��flag��һ�������ж��Ƿ���Ҫ�����������
    printf("�����׼����϶ĳ���ҵ����\n""x־�����߷��ƣ�\n");                        //x־��mdzz
    do{
        scanf("%s",roll);
        flag=1;
        if(strlen(roll)!=1);                    //����Ĳ��ǵ��ַ������������ҵģ�������
        else if(strlen(roll)==1){
            if(roll[0]=='y')printf("OK\n");
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