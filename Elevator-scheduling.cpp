#include<stdio.h>
#include <conio.h>
struct elevator
	{
		int t;//��ʱ��ʱ�� 
		int fl;//������ʱ��¥�� 
		int ok;//���ݷ��� 
		int num;//���������� 
	}ele;
struct  passenger
	{
		int t;//�˿ͷ��������ʱ�� 
		int begin;//�˿ͳ���¥�� 
		int end;//�˿�ȥ��¥�� 
		int ok1;//�˿͵ȴ�״̬ 
		int ok2;//�˿��Ƿ����
		int ok3;//�˿�ȥ������1Ϊ��¥2Ϊ��¥ 
	} a[100];	
void elev(int i)//����������ʱǰ��ָ��¥������ 
{
	int j;
	//printf("%d %d %d %d\n",ele.num,a[i].t,ele.t,a[i].ok2);
	
	if(ele.num==0&&a[i].t<=ele.t&&a[i].ok2==1)//�Ƿ��յ��˿����� 
	{
		if(a[i].begin>ele.fl)
		{
			for(j=0;j<a[i].begin-ele.fl;j++)//���� 
			{
			    ele.fl++;
			    ele.t++;
			}
			ele.ok=a[i].ok3;
		}
		else 
		{
			for(j=0;j<ele.fl-a[i].begin;j++)//���� 
			{
			    ele.fl--;
			    ele.t++;
			}
			ele.ok=a[i].ok3;
		}
		//printf("%d %d\n",ele.fl,ele.ok);
	}
	//printf("%d %d\n",ele.fl,ele.ok);
/*	else if(ele.num!=0&&a[i].t<=ele.t&&a[i].ok3==ele.ok&&a[i].ok2)//����������ʱ 
	{
		if(ele.ok==1&&(ele.fl>a[i].begin||ele.fl>a[i].end))
		ele.fl--;
		else if(ele.ok==2&&(ele.fl<a[i].begin||ele.fl<a[i].end))
		ele.fl++;
	}*/
}
int main()
{
	FILE *in;
	in=fopen("input.txt","rt");//���ļ� 
	ele.t=0;
	ele.fl=0;
	ele.ok=0;
	ele.num=0;
	int n,i,j,ok2=1,ok1;
	fscanf(in,"%d",&n);//����˿��� 
	for(i=0;i<n;i++)
	{ 
	      fscanf(in,"%d%d%d",&a[i].t,&a[i].begin,&a[i].end);//����˿���Ϣ 
	      a[i].ok1=0;
	      a[i].ok2=1;
	      if(a[i].begin>a[i].end)//�жϳ˿�ȥ������ 
	      a[i].ok3=1;
		  else
		  a[i].ok3=2; 
	}
	fclose(in);
	FILE *out; 
    extern clrscr();
    out=fopen("output.txt","wt");//д���ļ� 
	while(ok2)
	{
		//printf("%d",ok2);
		ok1=0;//�ж��Ƿ������ϵ��� 
		for(i=0;i<n;i++)
		{
			elev(i);
			//printf("%d %d %d %d %d %d %d %d\n",a[i].ok1,a[i].t,ele.t,a[i].ok2,a[i].begin,ele.fl,ele.ok,a[i].ok3);
			
		    if(a[i].ok1==0&&a[i].t<=ele.t&&a[i].ok2==1&&a[i].begin==ele.fl&&ele.ok==a[i].ok3)//�˿��ϵ��� 
		    {
		    	ele.num++;
			    a[i].ok1=1;
	    		ok1=1;
				//printf("**45**"); 
	    	//	ele.ok=a[i].ok3;
		    }
		   //printf("**%d %d %d %d\n",a[i].ok1,a[i].end,ele.fl,a[i].ok2);
		     if(a[i].ok1&&a[i].end==ele.fl&&a[i].ok2==1)//�˿��µ��� 
	    	{
	    		ele.num--;
	    		a[i].ok2=0;
	    		ok1=1;
				//printf("%d",ok2); 
	    	}
	    }
		if(ok1==1)//���ʱ�̺�¥�� 
		{
			fprintf(out,"%d %d\n",ele.t,ele.fl);
			ele.t++;
		}
		ele.t++;
		if(ele.ok==1)
		ele.fl--;
		else
		ele.fl++;
		ok2=0;
		ok1=0;
		for(i=0;i<n;i++)//�ж��Ƿ�ֹͣѭ�� 
		{
			ok2+=a[i].ok2;
		}
		//printf("%d\n",ok2);
	}
	fclose(out);
	return 0;
}









 
