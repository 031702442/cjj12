#include<stdio.h>
#include <conio.h>
struct elevator
	{
		int t;//此时的时间 
		int fl;//电梯这时的楼层 
		int ok;//电梯方向 
		int num;//电梯内人数 
	}ele;
struct  passenger
	{
		int t;//乘客发出请求的时刻 
		int begin;//乘客出发楼层 
		int end;//乘客去往楼层 
		int ok1;//乘客等待状态 
		int ok2;//乘客是否完成
		int ok3;//乘客去往方向1为下楼2为上楼 
	} a[100];	
void elev(int i)//当电梯无人时前往指定楼层载人 
{
	int j;
	//printf("%d %d %d %d\n",ele.num,a[i].t,ele.t,a[i].ok2);
	
	if(ele.num==0&&a[i].t<=ele.t&&a[i].ok2==1)//是否收到乘客请求 
	{
		if(a[i].begin>ele.fl)
		{
			for(j=0;j<a[i].begin-ele.fl;j++)//向上 
			{
			    ele.fl++;
			    ele.t++;
			}
			ele.ok=a[i].ok3;
		}
		else 
		{
			for(j=0;j<ele.fl-a[i].begin;j++)//向下 
			{
			    ele.fl--;
			    ele.t++;
			}
			ele.ok=a[i].ok3;
		}
		//printf("%d %d\n",ele.fl,ele.ok);
	}
	//printf("%d %d\n",ele.fl,ele.ok);
/*	else if(ele.num!=0&&a[i].t<=ele.t&&a[i].ok3==ele.ok&&a[i].ok2)//电梯内有人时 
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
	in=fopen("input.txt","rt");//打开文件 
	ele.t=0;
	ele.fl=0;
	ele.ok=0;
	ele.num=0;
	int n,i,j,ok2=1,ok1;
	fscanf(in,"%d",&n);//输入乘客数 
	for(i=0;i<n;i++)
	{ 
	      fscanf(in,"%d%d%d",&a[i].t,&a[i].begin,&a[i].end);//输入乘客信息 
	      a[i].ok1=0;
	      a[i].ok2=1;
	      if(a[i].begin>a[i].end)//判断乘客去往方向 
	      a[i].ok3=1;
		  else
		  a[i].ok3=2; 
	}
	fclose(in);
	FILE *out; 
    extern clrscr();
    out=fopen("output.txt","wt");//写入文件 
	while(ok2)
	{
		//printf("%d",ok2);
		ok1=0;//判断是否有人上电梯 
		for(i=0;i<n;i++)
		{
			elev(i);
			//printf("%d %d %d %d %d %d %d %d\n",a[i].ok1,a[i].t,ele.t,a[i].ok2,a[i].begin,ele.fl,ele.ok,a[i].ok3);
			
		    if(a[i].ok1==0&&a[i].t<=ele.t&&a[i].ok2==1&&a[i].begin==ele.fl&&ele.ok==a[i].ok3)//乘客上电梯 
		    {
		    	ele.num++;
			    a[i].ok1=1;
	    		ok1=1;
				//printf("**45**"); 
	    	//	ele.ok=a[i].ok3;
		    }
		   //printf("**%d %d %d %d\n",a[i].ok1,a[i].end,ele.fl,a[i].ok2);
		     if(a[i].ok1&&a[i].end==ele.fl&&a[i].ok2==1)//乘客下电梯 
	    	{
	    		ele.num--;
	    		a[i].ok2=0;
	    		ok1=1;
				//printf("%d",ok2); 
	    	}
	    }
		if(ok1==1)//输出时刻和楼层 
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
		for(i=0;i<n;i++)//判断是否停止循环 
		{
			ok2+=a[i].ok2;
		}
		//printf("%d\n",ok2);
	}
	fclose(out);
	return 0;
}









 
