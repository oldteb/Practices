#include<stdio.h>
#include<stdlib.h>

void InitTime(Time& t){
	t.hour   = 0;
	t.minute = 0;
}

void PrintTime(Time t){       //��ӡʱ��
	if(t.hour<10)  cout<<"0"<<t.hour;
	else  cout<<t.hour;
	cout<<":";
	if(t.minute<10)  cout<<"0"<<t.minute;
	else  cout<<t.minute;
}

void IntToTime(Time& time,int time1,int time2){
	time.hour   = time1;
	time.minute = time2;
}





Time AddTime(Time a1,Time a2){//��������ʱ���a1,a2��������ʱ��ε�ʱ��֮��
	Time sum;int sum_minute;
	sum.hour=a1.hour+a2.hour;
	sum_minute=a1.minute+a2.minute;
	if(sum_minute>=60){
		sum.minute=sum_minute-60;
		sum.hour=sum.hour+1;
	}
	else sum.minute=sum_minute;
	return sum;
}
int CompareTime(Time a1,Time a2){//�Ƚ�ʱ���a1,a2�ĳ��ȣ���a1����a2���򷵻أ����򷵻�
	if(a1.hour>a2.hour) return 1;
	else if(a1.hour==a2.hour&&a1.minute>a2.minute) return 1;
	return 0;
}
Time MinusTime(Time a1,Time a2){//����ʱ���a1,a2������a1��a2��ʱ�䳤��ֻ��
	Time minus;
	if(a1.minute<a2.minute){
		minus.minute=a1.minute+60-a2.minute;
		minus.hour=a1.hour-1-a2.hour;
	}
	else{
		minus.minute=a1.minute-a2.minute;
		minus.hour=a1.hour-a2.hour;
	}
	return minus;
}
