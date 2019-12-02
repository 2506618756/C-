#include <stdio.h>
#include <malloc.h>
#define PACK 3
#define WALK 10
#define Price 2
typedef struct
{
    int CarNum[PACK];
    int top;
}CarStack;

typedef struct
{
    int CarNum[WALK];
    int front,rear;
}CarQueue;

CarStack * InitStack()
{
	CarStack *s;
    s=(CarStack *)malloc(sizeof(CarStack));
    s->top=-1;
    return s;
}
int StackEmpty(CarStack *s)
{
    return(s->top==-1);
}
int StackFull(CarStack *s)
{
    return(s->top==PACK-1);
}
int Push(CarStack *s,int X)
{
    if (s->top==PACK-1)
        return 0;
    s->CarNum[++s->top]=X;
    return 1;
}
int Pop(CarStack *s)
{
    if (s->top==-1)
        return 0;
    return s->CarNum[s->top--];
}
void DispStack(CarStack *s)
{
    int i;
    for (i=s->top; i>=0; i--)
        printf("%d ",s->CarNum[i]);
    printf("\n");
}

CarQueue * InitQueue()
{
	CarQueue *q;
    q=(CarQueue *)malloc (sizeof(CarQueue));
    q->front=q->rear=0;
    return q;
}
int QueueEmpty(CarQueue *q)
{
    return(q->front==q->rear);
}
int QueueFull(CarQueue *q)
{
    return ((q->rear+1)%WALK==q->front);
}
int enQueue(CarQueue *q,int X)
{
    if ((q->rear+1)%WALK==q->front)
        return 0;
    q->rear=(q->rear+1)%WALK;
    q->CarNum[q->rear]=X;
    return 1;
}
int deQueue(CarQueue *q)
{
    if (q->front==q->rear)
        return 0;
    q->front=(q->front+1)%WALK;
    return q->CarNum[q->front];
}
void DispQueue(CarQueue *q)
{
    int i;
    i=(q->front+1)%WALK;
    printf("%d ",q->CarNum[i]);
    while ((q->rear-i+WALK)%WALK>0)
    {
        i=(i+1)%WALK;
        printf("%d ",q->CarNum[i]);
    }
    printf("\n");
}

int main()
{
    int dos;
    int num,time;
    int i,j,t;
    CarStack *St,*St1;
    CarQueue *Qu;
    St =  InitStack();
    St1 = InitStack();
    Qu =  InitQueue();
    do
    {
        printf("����ָ��(1:���� 2:�뿪 3:��ʾͣ���� 4:��ʾ�򳵳� 0:�˳�):");
        scanf("%d",&dos);
        switch(dos)
        {
        case 1:
            printf("�����복�ƺ�: ");
            scanf("%d",&num);
            if (!StackFull(St))
            {
                Push(St,num);
                printf("  >>ͣ����λ��:%d\n",St->top+1);
            }
            else
            {
                if (!QueueFull(Qu))
                {
                    enQueue(Qu,num);
                    printf("  >>�򳵳�λ��:%d\n",Qu->rear);
                }
                else
                    printf("  >>�򳵳�����,����ͣ��\n");
            }
            break;
        case 2:
            printf("�����복�ź�ͣ��ʱ��(����): ");
            scanf("%d%d",&num,&time);
            int number = num;
            for (i=0; i<=St->top && St->CarNum[i]!=num; i++);
            if (i>St->top)
                printf("  >>δ�ҵ��ñ�ŵ�����\n");
            else
            {
                t = St->top - i;
                for (j=0; j<t; j++)
                {
                    num = Pop(St);
                    Push(St1,num);
                }
                Pop(St);
                printf("  >>%d����ͣ������:%d\n",number,time*Price);
                while (!StackEmpty(St1))
                {
                    num = Pop(St1);
                    Push(St,num);
                }
                if (!QueueEmpty(Qu))
                {
                    num = deQueue(Qu);
                    Push(St,num);
                }
            }
            break;
        case 3:
            if (!StackEmpty(St))
            {
                printf("  >>ͣ�����еĳ���:");
                DispStack(St);
            }
            else
                printf("  >>ͣ�������޳���\n");
            break;
        case 4:
            if (!QueueEmpty(Qu))
            {
                printf("  >>�򳵳��еĳ���:");
                DispQueue(Qu);
            }
            else
                printf("  >>�򳵳����޳���\n");
            break;
        case 0:
            if (!StackEmpty(St))
            {
                printf("  >>ͣ�����еĳ���:");
                DispStack(St);
            }
            if (!QueueEmpty(Qu))
            {
                printf("  >>�򳵳��еĳ���:");
                DispQueue(Qu);
            }
            break;
        default:
            printf("  >>������������\n");
            break;
        }
    }
    while(dos!=0);
    return 0;
}
