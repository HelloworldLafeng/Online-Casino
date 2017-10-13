#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <time.h>
#define maxn 5

enum thetest{OK=0,NO=1,QUIT=2,AGAIN=3};
enum kind{fp=0,mh=1,heit=2,hongt=3};
struct feature{
    int num;
    enum kind kin;
}card[52];                                        //д��
const char * suit(struct feature i){              //��¼�˿��ƵĻ�ɫ
    if(i.kin==0)return"��Ƭ";
    else if(i.kin==1)return"÷��";
    else if(i.kin==2)return"����";
    else return"����";
}
char * number(struct feature i){                  //��¼�˿�����ֵ
    char *c= (char*)malloc(sizeof(char)*3);
    memset(c,0,sizeof(char)*3);
    if(i.num==1)
        c[0] = 'A';
    if(i.num>1&&i.num<10){
        c[0] = (char)i.num+(char)'0';
    }
    if(i.num==10)
        c[0]='1',c[1]='0';
    if(i.num==11)
        c[0]='J';
    if(i.num==12)
        c[0]='Q';
    if(i.num==13)
        c[0]='K';
    return c;
}
void playingcards(struct feature card[]){       //��ʼ���ƿ�
    for(int i=0;i<=3;i++){
        for(int n=1;n<=13;n++){
            card[i*13+n-1].num=n;           //������ֵJOK��δ���¶���
            card[i*13+n-1].kin=i;
        }
    }

}
void shuffle(struct feature a[],int n){       //ʹ��ϴ���㷨 ϴ��
    for(int i=0;i<n;i++){
        int tab=rand()%(n-i)+i;
        struct feature tab1;
        tab1=a[i];
        a[i]=a[tab];
        a[tab]=tab1;
    }
}
int choose(char *str){                         //�����������ִ�еĲ���
    if(strlen(str)==1){
        if(str[0]=='y')return OK;
        else if(str[0]=='n')return NO;
        else if(str[0]=='q')return QUIT;
        else return AGAIN;
    }
    else return AGAIN;
}
int wager(char *str){                        //�����ж��Ƿ���Ҫ�������г���Ѻע
    if(str[0]=='y')return OK;
    if(str[0]=='n')return NO;
}
int main(){
    printf("*********************����21����Ϸ*********************\n");
    int winner=0;
    int money[2];
    memset(money,0,sizeof(money));       //��ʼ���ܳ���
    money[0]=2500;
    money[1]=2500;
    int cash[2];                         //��ʼ��Ѻ��
    memset(cash,0,sizeof(cash));
    int run=0;                   //��ʼ
    while(run==0){             //�����Ƿ����¿�ʼ��Ϸ��   ��Ϸ��ʽ��ʼ���������
        int nsize=0;            //��¼ѡn�Ĵ�����������˶�ѡn��Ϸֱ�ӽ���ȷֻ���
        int n=0;                //׼�����ƿ��г�ȡ����
        int tip=0;              //����ؼ��������ж��Ƿ���Ҫ����������Ϸ��������һ����Ϸ
        int score[2];            //��¼���˵Ļ���
        memset(score,0,sizeof(score));      //���ֳ�ʼ��
        char str[10];
        playingcards(card);               //��ʼ���ƿ�
        srand((unsigned)time(NULL));
        shuffle(card,52);                   //ϴ��
        printf("��Ϸ������ʼ!\n");
        if(money[0]>0&&money[1]>0){
            printf("��������ҷֱ�ѡ����ҪѺע�ĳ�����������֪ͨ���������\n");
            printf("���1ӵ��%d���룬���2ӵ��%d����\n",money[0],money[1]);
            printf("���������1��ע����������Ѻע�ĳ���\n");
            scanf("%d",&cash[0]);
            money[0]-=cash[0];
            printf("���������2��ע����������Ѻע�ĳ���\n");
            scanf("%d",&cash[1]);
            money[1]-=cash[1];
        }         //Ѻע�Լ��жϳ��뻷��
        printf("���Ǳ�����Ϸ�ĵ�һ���غϣ����ڷַ���������ҵ�һ������\n");
        for(int j=1;j<=2;j++){                           //��һ�غ����˱�������
            char *num =number(card[n]);
            score[j-1]+=card[n].num;
            printf("���%d��������ʼ�����ǣ�%s%s��������ʼ������:%d\n",j,suit(card[n]),num,score[j-1]);
            n++;
        }
        for(int i=1;i<=2;i++){                       //�غϿ�ʼ��ʵ��������������
            printf("\n�����%dѡ���Ƿ��һ����,y/n/q\n",i);
            while(tip==0){                        //��tip=0��ζ������Ϸ�������У�tip=1�Ǳ�����Ϸ�����ı�ʶ
                scanf("%s",str);                   //���뷽�� y/n/q
                if(choose(str)==AGAIN)continue;
                else if(choose(str)==QUIT){
                    printf("���%dѡ�����䣬��Ϸ����������ʤ��������� ���%d\n",i,3-i);
                    tip = 1;                     //��һ�����ʧ�ܣ�������Ϸ����
                    winner=3-i;
                    break;
                }
                else if(choose(str)==NO){
                    nsize++;                   //ѡn��������
                    if(i==2&&nsize!=2)nsize=0;
                    printf("������ѡ�񲻳���\n");
                    printf("�����ڵĻ���Ϊ��%d\n",score[i-1]);
                    break;                       //break��while tip����һ����
                }
                else{
                    nsize=0;
                    char *num = number(card[n]);
                    printf("�㱾�ֳ�ȡ�Ŀ���Ϊ��%s%s\n",suit(card[n]),num);
                    free(num);
                    if(card[n].num>10)
                        card[n].num=10;
                    score[i-1]+=card[n].num;
                }
                printf("�����ڵĻ���Ϊ%d\n",score[i-1]);
                n++;                      //��������
                if(score[i-1]>=21){
                    printf("���%d�����ź������ˣ������ˡ�����ʤ��������� ���%d\n",i,3-i);
                    tip=1;
                    winner=3-i;
                    break;
                }
                break;
            }
            if(nsize==2){
                tip=1;
                if(score[0]==score[1]){
                    winner=0;
                    printf("������Ϸ����ƽ��\n");
                }
                else if(score[0]>score[1]){
                    printf("����ʤ��������� ���1\n");
                    winner=1;
                }
                else{
                    printf("����ʤ��������� ���2\n");
                    winner=2;
                }
            }
            if(tip==1&&winner!=0){
                money[winner-1]=money[winner-1]+cash[0]+cash[1];
                break;
            }
            if(tip==1&&winner==0){
                money[0]=money[0]+cash[0];
                money[1]=money[1]+cash[1];
                break;
            }
            if(i==2)i=0;
        }
        printf("������Ϸ�Ѿ����������ڹ������³��������\n���1ӵ��%d����,���2ӵ��%d����\n",money[0],money[1]);
        if(money[0]==0){
            printf("���1���볡�����2����ʤ����ӵ���ܹ�5000����");
            run=1;
            break;
        }
        if(money[1]==0){
            printf("���2���볡�����1����ʤ����ӵ���ܹ�5000����");
            run=1;
            break;
        }
        if(money[0]!=0&&money[1]!=0){
            char goon[5];
            int signal=0;
            for(int i=1;i<=2;i++){
                printf("�����%dѡ���Ƿ�Ҫ����������Ϸ��Ѻעy/n",i);
                scanf("%s",goon);
                if(wager(goon)==0)signal++;
            }
            if(signal!=2){
                run=1;
                printf("*********************��Ϸ����*********************\n");
                break;
            }
            if(signal==2){
                printf("*********************��Ϸ����*********************\n");
            }
        }
    }
    system("pause");
    return 0;
}