#include<iostream>
using namespace std;

int maxsize = 5;
int front = -1, rear = -1;
int queue[5];

void inqueue(){
	int item;
	cout<<"\nEnter the element\n";
	cin>>item;
	if((rear+1)%maxsize == front){
		cout<<"\nOVERFLOW";
		return;
	}
	else if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
	}
	else if(rear == maxsize -1 && front !=0)
	{
		rear = 0;
	}
	else
	{
		rear = (rear+1)%maxsize;
	}
	queue[rear] = item;
	cout<<"\nValue inserted \n";
}

void dequeue(){
	int item;
	if(front == -1 & rear == -1)
	{
		cout<<"\nUNDERFLOW\N";
		return;
	}
	else if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if(front == maxsize -1)
	{
		front = 0;
	}
	else
	front = front + 1;
}

void display(){
	int i;
	if(front == -1)
	cout<<"\nCircular queue is empty!\n";
	else{
		i = front;
		cout<<"\nCircular queue elements are : \n";
		if(front <=rear){
			while(i <= rear)
				cout<<"\n"<<queue[i++]<<front<<rear;
		}
		else{
			while(i <= maxsize -1)
				cout<<"\n"<<queue[i++]<<front<<rear;
				i = 0;
				while(i <= rear)
				cout<<"\n"<<queue[i++]<<front<<rear;
		}
	}
}

int main()
{
	int option;
	do{
		cout<<"1-inqueue \n 2-dequeue \n 3-show \n 4-exit\n";
		cout<<"Enter your option\n";
		cin>>option;
		
		switch(option)
		{
			case 1: inqueue(); break;
			case 2: dequeue(); break;
			case 3: display(); break;
			case 4: break;
			default: cout<<"Your option is not allowed";
		}
	}
	while(option !=4);
}